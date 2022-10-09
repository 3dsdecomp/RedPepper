#pragma once

#define NULL 0
#define nullptr NULL

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

typedef float f32;
typedef double f64;

typedef u32 uintptr_t;
typedef s32 intptr_t;

#define static_assert(COND, MSG) typedef int __static_assert_balls[(COND) ? 1 : -1]
