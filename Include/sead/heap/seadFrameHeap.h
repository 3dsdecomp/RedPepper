#pragma once

#include <sead/heap/seadHeap.h>

namespace sead {
class FrameHeap : public Heap {
    SEAD_RTTI_OVERRIDE(FrameHeap, Heap)
public:
    struct State {
        void* mHeadPtr;
        void* mTailPtr;
    };

    static FrameHeap* tryCreate(size_t size, const SafeString& name, Heap* parent, s32,
        HeapDirection direction, bool);
    static FrameHeap* create(size_t size, const SafeString& name, Heap* parent, s32,
        HeapDirection direction, bool);

    static size_t getManagementAreaSize(s32);

    void restoreState(const State& state);
    void freeHead();
    void freeTail();

    virtual void destroy();
    virtual size_t adjust();
    virtual void* tryAlloc(size_t size, s32 alignment);
    virtual void free(void* ptr);
    virtual void* resizeFront(void* p_void, size_t size);
    virtual void* resizeBack(void* p_void, size_t size);
    virtual void freeAll();
    virtual uintptr_t getStartAddress() const;
    virtual uintptr_t getEndAddress() const;
    virtual size_t getSize() const;
    virtual size_t getFreeSize() const;
    virtual size_t getMaxAllocatableSize(int alignment) const;
    virtual bool isInclude(const void* p_void) const;
    virtual bool isEmpty() const;
    virtual bool isFreeable() const;
    virtual bool isResizable() const;
    virtual bool isAdjustable() const;
    virtual void dump() const;
    virtual void dumpYAML(WriteStream& stream, int i) const;
    virtual void genInformation_(hostio::Context* context);

protected:
    FrameHeap(const SafeString& name, Heap* parent, void* address, size_t size,
        HeapDirection direction, bool);
    virtual ~FrameHeap();

    void initialize_();
    void* getAreaStart_() const;
    void* getAreaEnd_() const;

    State mState;
};
} // namespace sead
