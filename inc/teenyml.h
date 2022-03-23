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
#define CONST __attribute((const))
#define PURE __attribute((pure))
#define TEENYML_EXPORT OVERLOADABLE static inline

#define bail(...) do{printf("bailed at %d:%s:%s\n",__LINE__,__FUNCTION__,__FILE__);\
printf(__VA_ARGS__); exit(1);} while(0)

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
    TEENYML_EXPORT CONST s32 rank(tensor##rank_##_##type_##_t t){ return rank_; }

TENSOR_TYPE_GEN(u32, 3)





#endif //DEFINED_TEENYML_H
