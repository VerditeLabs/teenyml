
#pragma once
#ifndef DEFINED_TEENYML_H
#define DEFINED_TEENYML_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

#include <hedley.h>

#include "teenyml_macromagic_priv.h"


#define MAX_DIMS 8

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

//forward decls

struct tml_tensor1_u8_t;
struct tml_tensor2_u8_t;
struct tml_tensor3_u8_t;
struct tml_tensor4_u8_t;
struct tml_tensor5_u8_t;
struct tml_tensor6_u8_t;
struct tml_tensor7_u8_t;
struct tml_tensor8_u8_t;

struct tml_tensor1_u16_t;
struct tml_tensor2_u16_t;
struct tml_tensor3_u16_t;
struct tml_tensor4_u16_t;
struct tml_tensor5_u16_t;
struct tml_tensor6_u16_t;
struct tml_tensor7_u16_t;
struct tml_tensor8_u16_t;

struct tml_tensor1_u32_t;
struct tml_tensor2_u32_t;
struct tml_tensor3_u32_t;
struct tml_tensor4_u32_t;
struct tml_tensor5_u32_t;
struct tml_tensor6_u32_t;
struct tml_tensor7_u32_t;
struct tml_tensor8_u32_t;

struct tml_tensor1_u64_t;
struct tml_tensor2_u64_t;
struct tml_tensor3_u64_t;
struct tml_tensor4_u64_t;
struct tml_tensor5_u64_t;
struct tml_tensor6_u64_t;
struct tml_tensor7_u64_t;
struct tml_tensor8_u64_t;

struct tml_tensor1_s8_t;
struct tml_tensor2_s8_t;
struct tml_tensor3_s8_t;
struct tml_tensor4_s8_t;
struct tml_tensor5_s8_t;
struct tml_tensor6_s8_t;
struct tml_tensor7_s8_t;
struct tml_tensor8_s8_t;

struct tml_tensor1_s16_t;
struct tml_tensor2_s16_t;
struct tml_tensor3_s16_t;
struct tml_tensor4_s16_t;
struct tml_tensor5_s16_t;
struct tml_tensor6_s16_t;
struct tml_tensor7_s16_t;
struct tml_tensor8_s16_t;

struct tml_tensor1_s32_t;
struct tml_tensor2_s32_t;
struct tml_tensor3_s32_t;
struct tml_tensor4_s32_t;
struct tml_tensor5_s32_t;
struct tml_tensor6_s32_t;
struct tml_tensor7_s32_t;
struct tml_tensor8_s32_t;

struct tml_tensor1_s64_t;
struct tml_tensor2_s64_t;
struct tml_tensor3_s64_t;
struct tml_tensor4_s64_t;
struct tml_tensor5_s64_t;
struct tml_tensor6_s64_t;
struct tml_tensor7_s64_t;
struct tml_tensor8_s64_t;

struct tml_tensor1_f32_t;
struct tml_tensor2_f32_t;
struct tml_tensor3_f32_t;
struct tml_tensor4_f32_t;
struct tml_tensor5_f32_t;
struct tml_tensor6_f32_t;
struct tml_tensor7_f32_t;
struct tml_tensor8_f32_t;

struct tml_tensor1_f64_t;
struct tml_tensor2_f64_t;
struct tml_tensor3_f64_t;
struct tml_tensor4_f64_t;
struct tml_tensor5_f64_t;
struct tml_tensor6_f64_t;
struct tml_tensor7_f64_t;
struct tml_tensor8_f64_t;

union tml_tensor_f32_t;
union tml_tensor_f64_t;
union tml_tensor_u8_t;
union tml_tensor_u16_t;
union tml_tensor_u32_t;
union tml_tensor_u64_t;
union tml_tensor_s8_t;
union tml_tensor_s16_t;
union tml_tensor_s32_t;
union tml_tensor_s64_t;

union tml_tensor1_t;
union tml_tensor2_t;
union tml_tensor3_t;
union tml_tensor4_t;
union tml_tensor5_t;
union tml_tensor6_t;
union tml_tensor7_t;
union tml_tensor8_t;

union tml_tensor_t;

struct tml_dims1_t;
struct tml_dims2_t;
struct tml_dims3_t;
struct tml_dims4_t;
struct tml_dims5_t;
struct tml_dims6_t;
struct tml_dims7_t;
struct tml_dims8_t;
struct tml_dims_t;

struct tml_iter1_t;
struct tml_iter2_t;
struct tml_iter3_t;
struct tml_iter4_t;
struct tml_iter5_t;
struct tml_iter6_t;
struct tml_iter7_t;
struct tml_iter8_t;
struct tml_iter_t;


typedef enum tml_fill_type_e{
  FILL_TYPE_ZERO,
  FILL_TYPE_ONES,
  FILL_TYPE_INC,
  FILL_TYPE_DEC,
  FILL_TYPE_RAND,
}tml_fill_type_e;


typedef enum tml_dtype_e{
  DTYPE_U8,
  DTYPE_U16,
  DTYPE_U32,
  DTYPE_U64,
  DTYPE_S8,
  DTYPE_S16,
  DTYPE_S32,
  DTYPE_S64,
  DTYPE_F32,
  DTYPE_F64,
}tml_dtype_e;
/*
union tml_dims_t{
  tml_dims1_t d1;
  tml_dims2_t d2;
  tml_dims3_t d3;
  tml_dims4_t d4;
  tml_dims5_t d5;
  tml_dims6_t d6;
  tml_dims7_t d7;
  tml_dims8_t d8;
};
*/
#define TENSOR(RANK, T) TML__M_CONCAT5(tml_tensor, RANK, _, T, _t)
#define TENSOR_nodtype(RANK) TML__M_CONCAT3(tml_tensor, RANK, _t)
#define TENSOR_norank(T) TML__M_CONCAT4(tml_tensor, _, T, _t)
#define DIMS(RANK) TML__M_CONCAT3(tml_dims, RANK, _t)
#define ITER(RANK) TML__M_CONCAT3(tml_iter, RANK, _t)

#define T u8
#define RANK 1
#include "teenyml_dimsgen_priv.h"
#include "teenyml_itergen_priv.h"
#include "teenyml_tensorgen_priv.h"

union tml_tensor_f32_t{
  tml_tensor1_f32_t t1;
  tml_tensor2_f32_t t2;
  tml_tensor3_f32_t t3;
  tml_tensor4_f32_t t4;
  tml_tensor5_f32_t t5;
  tml_tensor6_f32_t t6;
  tml_tensor7_f32_t t7;
  tml_tensor8_f32_t t8;
};

union tml_tensor_f64_t{
  tml_tensor1_f64_t t1;
  tml_tensor2_f64_t t2;
  tml_tensor3_f64_t t3;
  tml_tensor4_f64_t t4;
  tml_tensor5_f64_t t5;
  tml_tensor6_f64_t t6;
  tml_tensor7_f64_t t7;
  tml_tensor8_f64_t t8;
};

union tml_tensor_u8_t{
  tml_tensor1_u8_t t1;
  tml_tensor2_u8_t t2;
  tml_tensor3_u8_t t3;
  tml_tensor4_u8_t t4;
  tml_tensor5_u8_t t5;
  tml_tensor6_u8_t t6;
  tml_tensor7_u8_t t7;
  tml_tensor8_u8_t t8;
};

union tml_tensor_u16_t{
  tml_tensor1_u16_t t1;
  tml_tensor2_u16_t t2;
  tml_tensor3_u16_t t3;
  tml_tensor4_u16_t t4;
  tml_tensor5_u16_t t5;
  tml_tensor6_u16_t t6;
  tml_tensor7_u16_t t7;
  tml_tensor8_u16_t t8;
};

union tml_tensor_u32_t{
  tml_tensor1_u32_t t1;
  tml_tensor2_u32_t t2;
  tml_tensor3_u32_t t3;
  tml_tensor4_u32_t t4;
  tml_tensor5_u32_t t5;
  tml_tensor6_u32_t t6;
  tml_tensor7_u32_t t7;
  tml_tensor8_u32_t t8;
};

union tml_tensor_u64_t{
  tml_tensor1_u64_t t1;
  tml_tensor2_u64_t t2;
  tml_tensor3_u64_t t3;
  tml_tensor4_u64_t t4;
  tml_tensor5_u64_t t5;
  tml_tensor6_u64_t t6;
  tml_tensor7_u64_t t7;
  tml_tensor8_u64_t t8;
};

union tml_tensor_s8_t{
  tml_tensor1_s8_t t1;
  tml_tensor2_s8_t t2;
  tml_tensor3_s8_t t3;
  tml_tensor4_s8_t t4;
  tml_tensor5_s8_t t5;
  tml_tensor6_s8_t t6;
  tml_tensor7_s8_t t7;
  tml_tensor8_s8_t t8;
};

union tml_tensor_s16_t{
  tml_tensor1_s16_t t1;
  tml_tensor2_s16_t t2;
  tml_tensor3_s16_t t3;
  tml_tensor4_s16_t t4;
  tml_tensor5_s16_t t5;
  tml_tensor6_s16_t t6;
  tml_tensor7_s16_t t7;
  tml_tensor8_s16_t t8;
};

union tml_tensor_s32_t{
  tml_tensor1_s32_t t1;
  tml_tensor2_s32_t t2;
  tml_tensor3_s32_t t3;
  tml_tensor4_s32_t t4;
  tml_tensor5_s32_t t5;
  tml_tensor6_s32_t t6;
  tml_tensor7_s32_t t7;
  tml_tensor8_s32_t t8;
};

union tml_tensor_s64_t{
  tml_tensor1_s64_t t1;
  tml_tensor2_s64_t t2;
  tml_tensor3_s64_t t3;
  tml_tensor4_s64_t t4;
  tml_tensor5_s64_t t5;
  tml_tensor6_s64_t t6;
  tml_tensor7_s64_t t7;
  tml_tensor8_s64_t t8;
};

union tml_tensor1_t{
  tml_tensor1_s8_t ts8;
  tml_tensor1_s16_t ts16;
  tml_tensor1_s32_t ts32;
  tml_tensor1_s64_t ts64;
  tml_tensor1_u8_t tu8;
  tml_tensor1_u16_t tu16;
  tml_tensor1_u32_t tu32;
  tml_tensor1_u64_t tu64;
  tml_tensor1_f32_t tf32;
  tml_tensor1_f64_t tf64;
};

union tml_tensor2_t{
  tml_tensor2_s8_t ts8;
  tml_tensor2_s16_t ts16;
  tml_tensor2_s32_t ts32;
  tml_tensor2_s64_t ts64;
  tml_tensor2_u8_t tu8;
  tml_tensor2_u16_t tu16;
  tml_tensor2_u32_t tu32;
  tml_tensor2_u64_t tu64;
  tml_tensor2_f32_t tf32;
  tml_tensor2_f64_t tf64;
};

union tml_tensor3_t{
  tml_tensor3_s8_t ts8;
  tml_tensor3_s16_t ts16;
  tml_tensor3_s32_t ts32;
  tml_tensor3_s64_t ts64;
  tml_tensor3_u8_t tu8;
  tml_tensor3_u16_t tu16;
  tml_tensor3_u32_t tu32;
  tml_tensor3_u64_t tu64;
  tml_tensor3_f32_t tf32;
  tml_tensor3_f64_t tf64;
};

union tml_tensor4_t{
  tml_tensor4_s8_t ts8;
  tml_tensor4_s16_t ts16;
  tml_tensor4_s32_t ts32;
  tml_tensor4_s64_t ts64;
  tml_tensor4_u8_t tu8;
  tml_tensor4_u16_t tu16;
  tml_tensor4_u32_t tu32;
  tml_tensor4_u64_t tu64;
  tml_tensor4_f32_t tf32;
  tml_tensor4_f64_t tf64;
};

union tml_tensor5_t{
  tml_tensor5_s8_t ts8;
  tml_tensor5_s16_t ts16;
  tml_tensor5_s32_t ts32;
  tml_tensor5_s64_t ts64;
  tml_tensor5_u8_t tu8;
  tml_tensor5_u16_t tu16;
  tml_tensor5_u32_t tu32;
  tml_tensor5_u64_t tu64;
  tml_tensor5_f32_t tf32;
  tml_tensor5_f64_t tf64;
};

union tml_tensor6_t{
  tml_tensor6_s8_t ts8;
  tml_tensor6_s16_t ts16;
  tml_tensor6_s32_t ts32;
  tml_tensor6_s64_t ts64;
  tml_tensor6_u8_t tu8;
  tml_tensor6_u16_t tu16;
  tml_tensor6_u32_t tu32;
  tml_tensor6_u64_t tu64;
  tml_tensor6_f32_t tf32;
  tml_tensor6_f64_t tf64;
};

union tml_tensor7_t{
  tml_tensor7_s8_t ts8;
  tml_tensor7_s16_t ts16;
  tml_tensor7_s32_t ts32;
  tml_tensor7_s64_t ts64;
  tml_tensor7_u8_t tu8;
  tml_tensor7_u16_t tu16;
  tml_tensor7_u32_t tu32;
  tml_tensor7_u64_t tu64;
  tml_tensor7_f32_t tf32;
  tml_tensor7_f64_t tf64;
};

union tml_tensor8_t{
  tml_tensor8_s8_t ts8;
  tml_tensor8_s16_t ts16;
  tml_tensor8_s32_t ts32;
  tml_tensor8_s64_t ts64;
  tml_tensor8_u8_t tu8;
  tml_tensor8_u16_t tu16;
  tml_tensor8_u32_t tu32;
  tml_tensor8_u64_t tu64;
  tml_tensor8_f32_t tf32;
  tml_tensor8_f64_t tf64;
};

union tml_tensor_t{
  tml_dtype_e dtype;
  s32 rank;
  tml_tensor_s8_t ts8;
  tml_tensor_s16_t ts16;
  tml_tensor_s32_t ts32;
  tml_tensor_s64_t ts64;
  tml_tensor_u8_t tu8;
  tml_tensor_u16_t tu16;
  tml_tensor_u32_t tu32;
  tml_tensor_u64_t tu64;
  tml_tensor_f32_t tf32;
  tml_tensor_f64_t tf64;
  tml_tensor1_t t1;
  tml_tensor2_t t2;
  tml_tensor3_t t3;
  tml_tensor4_t t4;
  tml_tensor5_t t5;
  tml_tensor6_t t6;
  tml_tensor7_t t7;
  tml_tensor8_t t8;
};

#include "teenyml_ops_priv.h"

#endif //DEFINED_TEENYML_H
