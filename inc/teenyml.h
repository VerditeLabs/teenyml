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

#define OVERLOADABLE __attribute__((overloadable))
#define CONST __attribute__((const))
#define PURE __attribute__((pure))
#define TEENYML_EXPORT OVERLOADABLE static inline

//#define OVERLOADABLE
//#define CONST
//#define PURE
//#define TEENYML_EXPORT

#define ANON_ARRAY(t, n, ...) (t[n]){__VA_ARGS__}

#define bail(...) do{printf("bailed at %d:%s:%s\n",__LINE__,__FUNCTION__,__FILE__); printf(__VA_ARGS__); exit(1);} while(0)

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

typedef union tml_vecbase_t {
  s32 raw[1];
} tml_vecbase_t;

#define DIMS_TYPE_GEN(rank_, ...) \
  typedef union tml_dims##rank_##_t { \
    s32 raw[rank_]; \
    struct {s32 __VA_ARGS__;}; \
  } tml_dims##rank_##_t; \
  TEENYML_EXPORT tml_dims##rank_##_t tml_dims##rank_ (s32 dims[static rank_]){ tml_dims##rank_##_t ret; memcpy(ret.raw,dims,rank_ * sizeof(rank_)); return ret;} \
  TEENYML_EXPORT s32 tml_rank(tml_dims##rank_##_t dims){ return rank_; } \
  TEENYML_EXPORT s32 tml_idx(tml_dims##rank_##_t extent, tml_dims##rank_##_t idx){ s32 i = 0, sz = 1; for(s32 _ = rank_ - 1; _ >= 0; _--) {i += idx.raw[_]*sz; sz*=extent.raw[_];} return i;}

DIMS_TYPE_GEN(1, x)
DIMS_TYPE_GEN(2, x, y)
DIMS_TYPE_GEN(3, x, y, z)
DIMS_TYPE_GEN(4, x, y, z, w)
DIMS_TYPE_GEN(5, x, y, z, w, i)
DIMS_TYPE_GEN(6, x, y, z, w, i, j)
DIMS_TYPE_GEN(7, x, y, z, w, i, j, k)
DIMS_TYPE_GEN(8, x, y, z, w, i, j, k, l)

typedef struct tml_tensorbase_t {
  u64 tag;
  s32 rank;
  void* data;
} tml_tensorbase_t;

TEENYML_EXPORT s32 tml_rank(tml_tensorbase_t  t) {
  bail("rank should not be called on tensorbase_t");
}

#define TENSOR_TYPE_GEN(type_, rank_)   \
  typedef struct tml_tensor##rank_##_##type_##_t { \
    u64 tag;              \
    s32 rank;             \
    s32 len; \
    type_ data[];             \
  }tml_tensor##rank_##_##type_##_t; \
  TEENYML_EXPORT s32 tml_rank(tml_tensor##rank_##_##type_##_t t){ return rank_; } \
  TEENYML_EXPORT s32 tml_at(tml_tensor##rank_##_##type_##_t t, tml_dims##rank_##_t d) { return 0; }

TENSOR_TYPE_GEN(u8, 1)
TENSOR_TYPE_GEN(u8, 2)
TENSOR_TYPE_GEN(u8, 3)
TENSOR_TYPE_GEN(u8, 4)
TENSOR_TYPE_GEN(u8, 5)
TENSOR_TYPE_GEN(u8, 6)
TENSOR_TYPE_GEN(u8, 7)
TENSOR_TYPE_GEN(u8, 8)
TENSOR_TYPE_GEN(u16, 1)
TENSOR_TYPE_GEN(u16, 2)
TENSOR_TYPE_GEN(u16, 3)
TENSOR_TYPE_GEN(u16, 4)
TENSOR_TYPE_GEN(u16, 5)
TENSOR_TYPE_GEN(u16, 6)
TENSOR_TYPE_GEN(u16, 7)
TENSOR_TYPE_GEN(u16, 8)
TENSOR_TYPE_GEN(u32, 1)
TENSOR_TYPE_GEN(u32, 2)
TENSOR_TYPE_GEN(u32, 3)
TENSOR_TYPE_GEN(u32, 4)
TENSOR_TYPE_GEN(u32, 5)
TENSOR_TYPE_GEN(u32, 6)
TENSOR_TYPE_GEN(u32, 7)
TENSOR_TYPE_GEN(u32, 8)
TENSOR_TYPE_GEN(u64, 1)
TENSOR_TYPE_GEN(u64, 2)
TENSOR_TYPE_GEN(u64, 3)
TENSOR_TYPE_GEN(u64, 4)
TENSOR_TYPE_GEN(u64, 5)
TENSOR_TYPE_GEN(u64, 6)
TENSOR_TYPE_GEN(u64, 7)
TENSOR_TYPE_GEN(u64, 8)

TENSOR_TYPE_GEN(s8, 1)
TENSOR_TYPE_GEN(s8, 2)
TENSOR_TYPE_GEN(s8, 3)
TENSOR_TYPE_GEN(s8, 4)
TENSOR_TYPE_GEN(s8, 5)
TENSOR_TYPE_GEN(s8, 6)
TENSOR_TYPE_GEN(s8, 7)
TENSOR_TYPE_GEN(s8, 8)
TENSOR_TYPE_GEN(s16, 1)
TENSOR_TYPE_GEN(s16, 2)
TENSOR_TYPE_GEN(s16, 3)
TENSOR_TYPE_GEN(s16, 4)
TENSOR_TYPE_GEN(s16, 5)
TENSOR_TYPE_GEN(s16, 6)
TENSOR_TYPE_GEN(s16, 7)
TENSOR_TYPE_GEN(s16, 8)
TENSOR_TYPE_GEN(s32, 1)
TENSOR_TYPE_GEN(s32, 2)
TENSOR_TYPE_GEN(s32, 3)
TENSOR_TYPE_GEN(s32, 4)
TENSOR_TYPE_GEN(s32, 5)
TENSOR_TYPE_GEN(s32, 6)
TENSOR_TYPE_GEN(s32, 7)
TENSOR_TYPE_GEN(s32, 8)
TENSOR_TYPE_GEN(s64, 1)
TENSOR_TYPE_GEN(s64, 2)
TENSOR_TYPE_GEN(s64, 3)
TENSOR_TYPE_GEN(s64, 4)
TENSOR_TYPE_GEN(s64, 5)
TENSOR_TYPE_GEN(s64, 6)
TENSOR_TYPE_GEN(s64, 7)
TENSOR_TYPE_GEN(s64, 8)

TENSOR_TYPE_GEN(f32, 1)
TENSOR_TYPE_GEN(f32, 2)
TENSOR_TYPE_GEN(f32, 3)
TENSOR_TYPE_GEN(f32, 4)
TENSOR_TYPE_GEN(f32, 5)
TENSOR_TYPE_GEN(f32, 6)
TENSOR_TYPE_GEN(f32, 7)
TENSOR_TYPE_GEN(f32, 8)
TENSOR_TYPE_GEN(f64, 1)
TENSOR_TYPE_GEN(f64, 2)
TENSOR_TYPE_GEN(f64, 3)
TENSOR_TYPE_GEN(f64, 4)
TENSOR_TYPE_GEN(f64, 5)
TENSOR_TYPE_GEN(f64, 6)
TENSOR_TYPE_GEN(f64, 7)
TENSOR_TYPE_GEN(f64, 8)



#endif //DEFINED_TEENYML_H
