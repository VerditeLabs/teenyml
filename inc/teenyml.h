//
// Created by forrest on 3/22/2022.
//
#pragma once
#ifndef DEFINED_TEENYML_H
#define DEFINED_TEENYML_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <hedley.h>

#define auto __auto_type

#define OVERLOADABLE __attribute__((overloadable))
#define CONST __attribute__((const))
#define PURE __attribute__((pure))
#define TEENYML_EXPORT OVERLOADABLE static inline

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

typedef enum tml_fill_type_e{
  FILL_TYPE_ZERO,
  FILL_TYPE_ONES,
  FILL_TYPE_INC,
  FILL_TYPE_DEC,
  FILL_TYPE_RAND,
}tml_fill_type_e;

#define TYPENAME(x) _Generic((x), \
  u8: "u8", u16: "u16", u32: "u32", u64: "u64", u128: "u128", \
  s8: "s8", s16: "s16", s32: "s32", s64: "s64", s128: "s128", \
  f32: "f32", f64: "f64")

#define ZERO(x)  _Generic((x), \
  u8: 0, u16: 0, u32: 0, u64: 0, u128: 0, \
  s8: 0, s16: 0, s32: 0, s64: 0, s128: 0, \
  f32: 0.0f, f64: 0.0)

#define ONE(x)  _Generic((x), \
  u8: 1, u16: 1, u32: 1, u64: 1, u128: 1, \
  s8: 1, s16: 1, s32: 1, s64: 1, s128: 1, \
  f32: 1.0f, f64: 1.0)

#define DIMS_TYPE_GEN(rank_, ...) \
  typedef union tml_dims##rank_##_t { \
    s32 raw[rank_]; \
    struct {s32 __VA_ARGS__;}; \
  } tml_dims##rank_##_t; \
  TEENYML_EXPORT tml_dims##rank_##_t tml_dims##rank_ (s32 dims[static rank_]){ \
    tml_dims##rank_##_t ret; memcpy(ret.raw,dims,rank_ * sizeof(s32)); return ret;\
  } \
  TEENYML_EXPORT tml_dims##rank_##_t tml_dims##rank_ (tml_dims##rank_##_t dims){ \
    tml_dims##rank_##_t ret; memcpy(ret.raw,dims.raw,rank_ * sizeof(s32)); return ret;\
  } \
  TEENYML_EXPORT s32 tml_rank(tml_dims##rank_##_t dims){ return rank_; } \
  TEENYML_EXPORT s32 tml_idx(tml_dims##rank_##_t extent, tml_dims##rank_##_t idx){ \
    s32 i = 0, sz = 1; \
    for(s32 _ = rank_ - 1; _ >= 0; _--) {\
      i += idx.raw[_]*sz; sz*=extent.raw[_]; \
    } \
    return i;\
  }                               \
  TEENYML_EXPORT tml_dims##rank_##_t tml_idx(tml_dims##rank_##_t extent, s32 idx){\
    s32 _ret[rank_] = {0};                              \
    s32 sz = 1; \
    for(s32 _ = rank_ - 1; _ >= 0; _--) {\
      sz*=extent.raw[_]; \ 
      _ret[_] = idx % sz; \
    } \
    return tml_dims##rank_(_ret); \
  } \
  TEENYML_EXPORT s32 tml_dims2len(tml_dims##rank_##_t dims) { \
    s32 ret = 1; \
    for(int i = 0; i < rank_; i++) ret*= dims.raw[i]; \
    return ret; \
  }

DIMS_TYPE_GEN(1, x)
DIMS_TYPE_GEN(2, x, y)
DIMS_TYPE_GEN(3, x, y, z)
DIMS_TYPE_GEN(4, x, y, z, w)
DIMS_TYPE_GEN(5, x, y, z, w, i)
DIMS_TYPE_GEN(6, x, y, z, w, i, j)
DIMS_TYPE_GEN(7, x, y, z, w, i, j, k)
DIMS_TYPE_GEN(8, x, y, z, w, i, j, k, l)

#define TENSOR_TYPE_GEN(type_, rank_)   \
  typedef struct tml_tensor##rank_##_##type_##_t { \
    u64 tag;              \
    tml_dims##rank_##_t extent; \
    type_ data[];             \
  }tml_tensor##rank_##_##type_##_t; \
  TEENYML_EXPORT tml_tensor##rank_##_##type_##_t* tml_tensor##rank_##_##type_(tml_dims##rank_##_t extent){\
    tml_tensor##rank_##_##type_##_t* ret =(tml_tensor##rank_##_##type_##_t*) malloc(sizeof(tml_tensor##rank_##_##type_##_t) + tml_dims2len(extent)*sizeof(type_));\
    ret->extent = extent; \
    return ret; \
  } \
  TEENYML_EXPORT s32 tml_rank(tml_tensor##rank_##_##type_##_t* tensor){ return rank_; } \
  TEENYML_EXPORT type_ tml_get(tml_tensor##rank_##_##type_##_t* tensor, tml_dims##rank_##_t idx) { return tensor->data[tml_idx(tensor->extent, idx)]; }\
  TEENYML_EXPORT type_ tml_get(tml_tensor##rank_##_##type_##_t* tensor, s32 idx) { return tensor->data[idx]; }\
  TEENYML_EXPORT void tml_set(tml_tensor##rank_##_##type_##_t* tensor, tml_dims##rank_##_t idx, type_ data) { tensor->data[tml_idx(tensor->extent, idx)] = data; }\
  TEENYML_EXPORT void tml_set(tml_tensor##rank_##_##type_##_t* tensor, s32 idx, type_ data) { tensor->data[idx] = data; } \
  TEENYML_EXPORT void tml_fill(tml_tensor##rank_##_##type_##_t* tensor, tml_fill_type_e fill) {\
    switch (fill) {\
    case FILL_TYPE_ZERO:for (int _ = 0; _ < tml_dims2len(tensor->extent); _++) { tml_set(tensor, _, ZERO(tensor->data[0])); } break; \
    case FILL_TYPE_ONES:for (int _ = 0; _ < tml_dims2len(tensor->extent); _++) { tml_set(tensor, _, ONE(tensor->data[0])); } break; \
    case FILL_TYPE_INC:break; \
    case FILL_TYPE_DEC:break; \
    case FILL_TYPE_RAND:break; \
    } \
  }

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
