#pragma once

#include <new>
#include <sead/basis/seadTypes.h>
#include <sead/heap/seadHeap.h>
#include <stddef.h>

void* operator new(std::size_t size, const std::nothrow_t&) throw();
void* operator new[](std::size_t size, const std::nothrow_t&) throw();

void* operator new(size_t size, s32 alignment);
void* operator new[](size_t size, s32 alignment);

void* operator new(size_t size, sead::Heap* heap, s32 alignment = sizeof(void*));
void* operator new[](size_t size, sead::Heap* heap, s32 alignment = sizeof(void*));

void operator delete(void* ptr, s32);
void operator delete[](void* ptr, s32);

void operator delete(void* ptr, sead::Heap*, s32);
void operator delete[](void* ptr, sead::Heap*, s32);
