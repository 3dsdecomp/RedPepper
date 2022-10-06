#pragma once

#define NULL 0
#define nullptr NULL

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

#define static_assert(COND, MSG) \
    extern int __static_assert_balls[(COND) ? 1 : -1]
