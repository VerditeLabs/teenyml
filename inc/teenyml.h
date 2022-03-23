//
// Created by forrest on 3/22/2022.
//
#pragma once
#ifndef DEFINED_TEENYML_H
#define DEFINED_TEENYML_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#define auto __auto_type

//#define OVERLOADABLE __attribute__((overloadable))
//#define CONST __attribute__((const))
//#define PURE __attribute__((pure))
//#define TEENYML_EXPORT OVERLOADABLE static inline

#define OVERLOADABLE
#define CONST
#define PURE
#define TEENYML_EXPORT

#define bail(...) do{printf("bailed at %d:%s:%s\n",__LINE__,__FUNCTION__,__FILE__);\
printf(__VA_ARGS__); exit(1);} while(0)

// Make a FOREACH macro
#define FE_0(WHAT)
#define FE_1(WHAT, X) WHAT(X) 
#define FE_2(WHAT, X, ...) WHAT(X)FE_1(WHAT, __VA_ARGS__)
#define FE_3(WHAT, X, ...) WHAT(X)FE_2(WHAT, __VA_ARGS__)
#define FE_4(WHAT, X, ...) WHAT(X)FE_3(WHAT, __VA_ARGS__)
#define FE_5(WHAT, X, ...) WHAT(X)FE_4(WHAT, __VA_ARGS__)
//... repeat as needed

#define GET_MACRO(_0,_1,_2,_3,_4,_5,NAME,...) NAME 
#define FOR_EACH(action,...) \
  GET_MACRO(_0,__VA_ARGS__,FE_5,FE_4,FE_3,FE_2,FE_1,FE_0)(action,__VA_ARGS__)


#define S32IFY(X)   s32 X 



typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned __int128 u128;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef __int128 s128;

typedef float f32;
typedef double f64;

typedef union vecbase_t {
    s32 raw[1];
}vecbase_t;

#define DIMS_TYPE_GEN(rank_, ...)     \
    typedef union dims##rank_##_t { \
      s32 raw[rank_]; \
      struct {s32 __VA_ARGS__;}; \
    } dims##rank_##_t; \
    TEENYML_EXPORT CONST dims##rank_##_t dims##rank_## (FOR_EACH(S32IFY, __VA_ARGS__ )){} \
    TEENYML_EXPORT CONST s32 rank(dims##rank_##_t dims){ return rank_; } \
    TEENYML_EXPORT CONST s32 idx(dims##rank_##_t dims, dims##rank_##_t idx){ s32 i = 0, sz = 1; for(s32 _ = rank_ - 1; _ >= 0; _--) {i += idx.raw[_]*sz; sz*=dims.raw[_];} return i;}

DIMS_TYPE_GEN(1, x)
DIMS_TYPE_GEN(2, x, y)
DIMS_TYPE_GEN(3, x, y, z)
DIMS_TYPE_GEN(4, x, y, z, w)
DIMS_TYPE_GEN(5, x, y, z, w, i)
DIMS_TYPE_GEN(6, x, y, z, w, i, j)
DIMS_TYPE_GEN(7, x, y, z, w, i, j, k)
DIMS_TYPE_GEN(8, x, y, z, w, i, j, k, l)

typedef struct tensorbase_t {
    u64 tag;
    s32 rank;
    void* data;
} tensorbase_t;

TEENYML_EXPORT CONST s32 rank(tensorbase_t  t) {
    bail("rank should not be called on tensorbase_t");
}

#define TENSOR_TYPE_GEN(type_, rank_)     \
    typedef struct tensor##rank_##_##type_##_t { \
      u64 tag;                          \
      s32 rank;                         \
      type_* data;                       \
    }tensor##rank_##_##type_##_t; \
    TEENYML_EXPORT CONST s32 rank(tensor##rank_##_##type_##_t t){ return rank_; } \
    TEENYML_EXPORT CONST s32 at(tensor##rank_##_##type_##_t t, dims##rank_##_t d) { return 0; }

TENSOR_TYPE_GEN(u32, 2)





#endif //DEFINED_TEENYML_H
