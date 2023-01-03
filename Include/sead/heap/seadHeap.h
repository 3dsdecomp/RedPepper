#ifndef SEAD_HEAP_H_
#define SEAD_HEAP_H_

#include <stddef.h>

#include <sead/basis/seadRawPrint.h>
#include <sead/basis/seadTypes.h>
#include <sead/container/seadOffsetList.h>
#include <sead/heap/seadDisposer.h>
#include <sead/prim/seadBitFlag.h>
#include <sead/prim/seadNamable.h>
#include <sead/prim/seadRuntimeTypeInfo.h>
#include <sead/prim/seadSafeString.h>
#include <sead/thread/seadCriticalSection.h>

namespace sead {
class Thread;
class WriteStream;

namespace hostio {
    class Context;
    class PropertyEvent;
} // namespace hostio

class Heap : public IDisposer, public INamable {
public:
    enum HeapDirection {
        cHeapDirection_Forward = 1,
        cHeapDirection_Reverse = -1
    };

    Heap(const SafeString& name, Heap* parent, void* address, size_t size, HeapDirection direction,
        bool);
    virtual ~Heap();

    SEAD_RTTI_BASE(Heap)

    virtual void destroy() = 0;
    virtual size_t adjust() = 0;
    virtual void* tryAlloc(size_t size, s32 alignment) = 0;
    virtual void free(void* ptr) = 0;
    virtual void* resizeFront(void*, size_t) = 0;
    // virtual void* resizeBack(void*, size_t) = 0;
    virtual void* tryRealloc(void* ptr, size_t size, s32 alignment);
    virtual void freeAll() = 0;
    virtual uintptr_t getStartAddress() const = 0;
    virtual uintptr_t getEndAddress() const = 0;
    virtual size_t getSize() const = 0;
    virtual size_t getFreeSize() const = 0;
    virtual size_t getMaxAllocatableSize(int alignment) const = 0;
    virtual bool isInclude(const void*) const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFreeable() const = 0;
    virtual bool isResizable() const = 0;
    virtual bool isAdjustable() const = 0;

    virtual void dump() const { }
    virtual void dumpYAML(WriteStream& stream, int) const;
    void dumpTreeYAML(WriteStream& stream, int) const;

#ifdef SEAD_DEBUG
    void listenPropertyEvent(const hostio::PropertyEvent* event) override;
    void genMessage(hostio::Context*) override;
#endif
    virtual void genInformation_(hostio::Context*);
    virtual void makeMetaString_(BufferedSafeString*);

    virtual void pushBackChild_(Heap* child);

    void appendDisposer_(IDisposer* disposer);
    void removeDisposer_(IDisposer* disposer);
    Heap* findContainHeap_(const void* ptr);

    void* alloc(size_t size, s32 alignment = sizeof(void*))
    {
        void* ptr = tryAlloc(size, alignment);
        SEAD_ASSERT_MSG(ptr,
            "alloc failed. size: %zu, allocatable size: %zu, alignment: %d, heap: %s",
            size, getMaxAllocatableSize(alignment), alignment, getName().cstr());
        return ptr;
    }

    sead::CriticalSection& getCriticalSection() { return mCS; }

    typedef OffsetList<Heap> HeapList;
    typedef OffsetList<IDisposer> DisposerList;

    void* mStart;
    size_t mSize;
    Heap* mParent;
    HeapList mChildren;
    ListNode mListNode;
    DisposerList mDisposerList;
    HeapDirection mDirection;
    CriticalSection mCS;
    BitFlag16 mFlag;
    u16 mHeapCheckTag;
#ifdef SEAD_DEBUG
    sead::Thread* mAccessThread;
#endif
};

inline void* Heap::tryRealloc(void*, size_t, s32)
{
    SEAD_ASSERT_MSG(false, "tryRealloc is not implement.");
    return nullptr;
}

} // namespace sead

#endif // SEAD_HEAP_H_
