#ifndef SEAD_FILEDEVICE_H_
#define SEAD_FILEDEVICE_H_

#include <sead/basis/seadTypes.h>
#include <sead/container/seadSafeArray.h>
#include <sead/container/seadTList.h>
#include <sead/heap/seadDisposer.h>
#include <sead/heap/seadHeap.h>
#include <sead/prim/seadRuntimeTypeInfo.h>
#include <sead/prim/seadSafeString.h>

namespace sead {
class FileDevice;

typedef SafeArray<u8, 32> HandleBuffer;

class HandleBase {
public:
    HandleBase()
        : mDevice(nullptr)
        , mOriginalDevice(nullptr) {};
    virtual ~HandleBase() {};

    FileDevice* getDevice() const { return mDevice; }
    FileDevice* getOriginalDevice() const { return mOriginalDevice; }
    bool isOpened() const { return mOriginalDevice != nullptr; }

protected:
    friend class FileDevice;

    FileDevice* mDevice;
    FileDevice* mOriginalDevice;
    HandleBuffer mHandleBuffer;
};

class FileHandle;
class DirectoryHandle;
struct DirectoryEntry;

class FileDevice : public TListNode<FileDevice*>, public IDisposer {
    SEAD_RTTI_BASE(FileDevice)

public:
    enum FileOpenFlag {
        cFileOpenFlag_ReadOnly = 0, // r
        cFileOpenFlag_WriteOnly = 1, // w
        cFileOpenFlag_ReadWrite = 2, // r+
        cFileOpenFlag_Create = 3 // w+
    };

    enum SeekOrigin {
        cSeekOrigin_Begin = 0,
        cSeekOrigin_Current = 1,
        cSeekOrigin_End = 2
    };

    struct LoadArg {
        LoadArg()
            : buffer(nullptr)
            , buffer_size(0)
            , heap(nullptr)
            , alignment(0)
            , buffer_size_alignment(0)
            , div_size(0)
            , assert_on_alloc_fail(true)
            , check_read_entire_file(true)
            , read_size(0)
            , roundup_size(0)
            , need_unload(false)
        {
        }

        SafeString path;
        u8* buffer;
        u32 buffer_size;
        Heap* heap;
        s32 alignment;
        s32 buffer_size_alignment;
        /// Read chunk size
        u32 div_size;
        bool assert_on_alloc_fail;
        bool check_read_entire_file;
        u32 read_size;
        u32 roundup_size;
        bool need_unload;
    };

    struct SaveArg {
        SaveArg()
            : path("")
            , buffer(nullptr)
            , buffer_size(0)
            , write_size(0)
        {
        }

        SafeString path;
        const u8* buffer;
        u32 buffer_size;
        u32 write_size;
    };

public:
    FileDevice()
        : TListNode<FileDevice*>(this)
        , IDisposer()
        , mDriveName()
        , mPermission(true)
    {
    }

    explicit FileDevice(const SafeString& name)
        : TListNode<FileDevice*>(this)
        , IDisposer()
        , mDriveName()
        , mPermission(true)
    {
        setDriveName(name);
    }

    virtual ~FileDevice();

    const SafeString& getDriveName() const { return mDriveName; }
    void setDriveName(const SafeString& name)
    {
#ifdef SEAD_DEBUG
        if (name.include(':'))
            SEAD_WARN("drive name should not include ':'. (in %s)", name.cstr());
#endif
        mDriveName = name;
    }

    bool hasPermission() const { return mPermission; }
    void setHasPermission(bool perm) { mPermission = perm; }

    bool isAvailable() const;

    u8* tryLoad(LoadArg& arg);

    bool save(SaveArg& arg)
    {
        if (!trySave(arg)) {
            SEAD_ASSERT_MSG(false, "file save error");
            return false;
        }
        return true;
    }
    bool trySave(SaveArg& arg);

    FileDevice* open(FileHandle* handle, const SafeString& path, FileOpenFlag flag, u32 divSize = 0)
    {
        FileDevice* device = tryOpen(handle, path, flag, divSize);
        if (!device) {
            SEAD_ASSERT_MSG(false, "file open error");
            return nullptr;
        }
        return device;
    }
    FileDevice* tryOpen(FileHandle* handle, const SafeString& path, FileOpenFlag flag,
        u32 divSize = 0);

    bool close(FileHandle* handle)
    {
        if (!tryClose(handle)) {
            SEAD_ASSERT_MSG(false, "file close error");
            return false;
        }
        return true;
    }
    bool tryClose(FileHandle* handle);

    bool flush(FileHandle* handle)
    {
        if (!tryFlush(handle)) {
            SEAD_ASSERT_MSG(false, "file flush error");
            return false;
        }
        return true;
    }
    bool tryFlush(FileHandle* handle);

    bool remove(const SafeString& str)
    {
        if (!tryRemove(str)) {
            SEAD_ASSERT_MSG(false, "file remove error");
            return false;
        }
        return true;
    }
    bool tryRemove(const SafeString& str);

    u32 read(FileHandle* handle, u8* data, u32 size)
    {
        u32 bytes_read = 0;
        if (!tryRead(&bytes_read, handle, data, size))
            SEAD_ASSERT_MSG(false, "file read error");
        return bytes_read;
    }
    bool tryRead(u32* bytesRead, FileHandle* handle, u8* outBuffer, u32 bytesToRead);

    u32 write(FileHandle* handle, const u8* data, u32 size)
    {
        u32 bytes_written = 0;
        if (!tryWrite(&bytes_written, handle, data, size))
            SEAD_ASSERT_MSG(false, "file write error");
        return bytes_written;
    }
    bool tryWrite(u32* bytesWritten, FileHandle* handle, const u8* inBuffer, u32 bytesToWrite);

    bool seek(FileHandle* handle, s32 offset, SeekOrigin origin)
    {
        if (!trySeek(handle, offset, origin)) {
            SEAD_ASSERT_MSG(false, "file seek error");
            return false;
        }
        return true;
    }
    bool trySeek(FileHandle* handle, s32 offset, SeekOrigin origin);

    u32 getCurrentSeekPos(FileHandle* handle)
    {
        u32 seek_pos = 0;
        if (!tryGetCurrentSeekPos(&seek_pos, handle))
            SEAD_ASSERT_MSG(false, "tryGetCurrentSeekPos error");
        return seek_pos;
    }
    bool tryGetCurrentSeekPos(u32* seekPos, FileHandle* handle);

    u32 getFileSize(const SafeString& path)
    {
        u32 file_size = 0;
        if (!tryGetFileSize(&file_size, path))
            SEAD_ASSERT_MSG(false, "tryGetFileSize error");
        return file_size;
    }
    bool tryGetFileSize(u32* fileSize, const SafeString& path);

    u32 getFileSize(FileHandle* handle)
    {
        u32 file_size = 0;
        if (!tryGetFileSize(&file_size, handle))
            SEAD_ASSERT_MSG(false, "tryGetFileSize error");
        return file_size;
    }
    bool tryGetFileSize(u32* size, FileHandle* handle);

    bool isExistFile(const SafeString& path)
    {
        bool exists = false;
        if (!tryIsExistFile(&exists, path))
            SEAD_ASSERT_MSG(false, "tryIsExistFile error");
        return exists;
    }
    bool tryIsExistFile(bool* exists, const SafeString& path);

    bool isExistDirectory(const SafeString& path)
    {
        bool exists = false;
        if (!tryIsExistDirectory(&exists, path))
            SEAD_ASSERT_MSG(false, "isExistDirectory failed");
        return exists;
    }
    bool tryIsExistDirectory(bool* exists, const SafeString& path);

    FileDevice* openDirectory(DirectoryHandle* handle, const SafeString& path)
    {
        FileDevice* device = tryOpenDirectory(handle, path);
        if (!device) {
            SEAD_ASSERT_MSG(false, "directory open error");
            return nullptr;
        }
        return device;
    }
    FileDevice* tryOpenDirectory(DirectoryHandle* handle, const SafeString& path);

    bool closeDirectory(DirectoryHandle* handle)
    {
        if (!tryCloseDirectory(handle)) {
            SEAD_ASSERT_MSG(false, "directory close error");
            return false;
        }
        return true;
    }
    bool tryCloseDirectory(DirectoryHandle* handle);

    u32 readDirectory(DirectoryHandle* handle, DirectoryEntry* entries, u32 num_entries)
    {
        u32 entries_read = 0;
        if (!tryReadDirectory(&entries_read, handle, entries, num_entries))
            SEAD_ASSERT_MSG(false, "directory read error");
        return entries_read;
    }
    bool tryReadDirectory(u32* entriesRead, DirectoryHandle* handle, DirectoryEntry* entries,

        u32 entriesToRead);

    bool makeDirectory(const SafeString& path, u32 x)
    {
        if (!tryMakeDirectory(path, x)) {
            SEAD_ASSERT_MSG(false, "directory make error");
            return false;
        }
        return true;
    }
    bool tryMakeDirectory(const SafeString& path, u32);

    bool makeDirectoryWithParent(const SafeString& path, u32 x)
    {
        if (!tryMakeDirectoryWithParent(path, x)) {
            SEAD_ASSERT_MSG(false, "directory make with parent error");
            return false;
        }
        return true;
    }
    bool tryMakeDirectoryWithParent(const SafeString& path, u32);

    s32 getLastRawError() const;

    virtual void traceFilePath(const SafeString& path) const;
    virtual void traceDirectoryPath(const SafeString& path) const;
    virtual void resolveFilePath(BufferedSafeString* out, const SafeString& path) const;
    virtual void resolveDirectoryPath(BufferedSafeString* out, const SafeString& path) const;
    virtual bool isMatchDevice_(const HandleBase* handle) const;

#ifdef SWITCH
    static const s32 cBufferMinAlignment = 0x20;
#else
    static const s32 cBufferMinAlignment = 0x40;
#endif

protected:
    virtual bool doIsAvailable_() const = 0;
    virtual u8* doLoad_(LoadArg& arg);
    virtual bool doSave_(SaveArg& arg);
    virtual FileDevice* doOpen_(FileHandle* handle, const SafeString& path, FileOpenFlag flag) = 0;
    virtual bool doClose_(FileHandle* handle) = 0;
    virtual bool doFlush_(FileHandle* handle) = 0;
    virtual bool doRemove_(const SafeString& str) = 0;
    virtual bool doRead_(u32* bytesRead, FileHandle* handle, u8* outBuffer, u32 bytesToRead) = 0;
    virtual bool doWrite_(u32* bytesWritten, FileHandle* handle, const u8* inBuffer,
        u32 bytesToWrite)
        = 0;
    virtual bool doSeek_(FileHandle* handle, s32 offset, SeekOrigin origin) = 0;
    virtual bool doGetCurrentSeekPos_(u32* seekPos, FileHandle* handle) = 0;
    virtual bool doGetFileSize_(u32* fileSize, const SafeString& path) = 0;
    virtual bool doGetFileSize_(u32* fileSize, FileHandle* handle) = 0;
    virtual bool doIsExistFile_(bool* exists, const SafeString& path) = 0;
    virtual bool doIsExistDirectory_(bool* exists, const SafeString& path) = 0;
    virtual FileDevice* doOpenDirectory_(DirectoryHandle* handle, const SafeString& path) = 0;
    virtual bool doCloseDirectory_(DirectoryHandle* handle) = 0;
    virtual bool doReadDirectory_(u32* entriesRead, DirectoryHandle* handle,
        DirectoryEntry* entries, u32 entriesToRead)
        = 0;
    virtual bool doMakeDirectory_(const SafeString& path, u32) = 0;
    virtual s32 doGetLastRawError_() const = 0;
    virtual void doTracePath_(const SafeString& path) const;
    virtual void doResolvePath_(BufferedSafeString* out, const SafeString& path) const;

    void setFileHandleDivSize_(FileHandle* handle, u32 divSize) const;
    void setHandleBaseFileDevice_(HandleBase* handle, FileDevice* device) const;
    void setHandleBaseOriginalFileDevice_(HandleBase* handle, FileDevice* device) const;
    HandleBuffer& getHandleBaseHandleBuffer_(HandleBase* handle) const;

    FixedSafeString<32> mDriveName;
    bool mPermission;
};

class FileHandle : public HandleBase {
public:
    FileHandle()
        : HandleBase()
        , mDivSize(0)
    {
    }

    virtual ~FileHandle()
    {
        FileDevice* _device = mOriginalDevice;
        if (_device != NULL)
            _device->tryClose(this);
    }

    bool close();
    bool tryClose();

    bool flush();
    bool tryFlush();

    u32 read(u8* outBuffer, u32 bytesToRead);
    bool tryRead(u32* actual_size, u8* data, u32 size);

    u32 write(const u8* data, u32 size);
    bool tryWrite(u32* actual_size, const u8* data, u32 size);

    bool seek(s32 offset, FileDevice::SeekOrigin origin);
    bool trySeek(s32 offset, FileDevice::SeekOrigin origin);
    u32 getCurrentSeekPos();
    bool tryGetCurrentSeekPos(u32* pos);

    u32 getFileSize();
    bool tryGetFileSize(u32* size);

    u32 getDivSize() const { return mDivSize; }

protected:
    friend class FileDevice;

    s32 mDivSize;
};

class DirectoryHandle : public HandleBase {
public:
    DirectoryHandle()
        : HandleBase()
    {
    }

    virtual ~DirectoryHandle()
    {
        FileDevice* _device = mOriginalDevice;
        if (_device != NULL)
            _device->tryCloseDirectory(this);
    }

    bool close();
    bool tryClose();
    u32 read(DirectoryEntry* entries, u32 count);
    bool tryRead(u32* actual_count, DirectoryEntry* entries, u32 count);
};

struct DirectoryEntry {
    DirectoryEntry()
        : name()
        , is_directory(false)
    {
    }

    FixedSafeString<256> name;
    bool is_directory;
};

} // namespace sead

#endif // SEAD_FILEDEVICE_H_
