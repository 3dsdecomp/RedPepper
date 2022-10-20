#pragma once

#include <new>
#include <sead/basis/seadTypes.h>
#include <stddef.h>

namespace sead {

class Heap;

} // namespace sead

void* operator new(std::size_t size, const std::nothrow_t&) throw();
void* operator new[](std::size_t size, const std::nothrow_t&) throw();

void* operator new(size_t size, s32 alignment) throw();
void* operator new[](size_t size, s32 alignment) throw();

void* operator new(size_t size, sead::Heap* heap, s32 alignment = sizeof(void*)) throw();
void* operator new[](size_t size, sead::Heap* heap, s32 alignment = sizeof(void*)) throw();

void operator delete(void* ptr, s32);
void operator delete[](void* ptr, s32);

void operator delete(void* ptr, sead::Heap*, s32);
void operator delete[](void* ptr, sead::Heap*, s32);
