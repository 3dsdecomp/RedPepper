#ifndef SEAD_CRITICAL_SECTION_H_
#define SEAD_CRITICAL_SECTION_H_

#include <sead/basis/seadTypes.h>
#include <sead/heap/seadDisposer.h>

namespace sead {
class Heap;

class CriticalSection : public IDisposer {
public:
    CriticalSection();
    explicit CriticalSection(Heap* disposer_heap);
    CriticalSection(Heap* disposer_heap, HeapNullOption heap_null_option);
    virtual ~CriticalSection();

    void lock();
    bool tryLock();
    void unlock();

    // For compatibility with the standard Lockable concept.
    bool try_lock() { return tryLock(); }

    // mutex
};

} // namespace sead

#endif // SEAD_CRITICAL_SECTION_H_
