#pragma once

#include <new>
#include <sead/basis/seadTypes.h>
#include <sead/heap/seadHeap.h>
#include <stddef.h>

void* operator new(size_t size) throw(std::bad_alloc); // need nothrow version to fix nullptr checks
void* operator new[](size_t size) throw(std::bad_alloc);

void* operator new(size_t size, s32 alignment);
void* operator new[](size_t size, s32 alignment);

void* operator new(size_t size, sead::Heap* heap, s32 alignment = sizeof(void*));
void* operator new[](size_t size, sead::Heap* heap, s32 alignment = sizeof(void*));

void operator delete(void* ptr, s32);
void operator delete[](void* ptr, s32);

void operator delete(void* ptr, sead::Heap*, s32);
void operator delete[](void* ptr, sead::Heap*, s32);
