
#pragma once
#ifndef TEENYML_TEENYML_OPS_PRIV_H
#define TEENYML_TEENYML_OPS_PRIV_H

#define DTYPE_MAX(type_) Generic((type_), \
              u8: UCHAR_MAX, \
              u16: USHRT_MAX, \
              u32: UINT_MAX, \
              u64: ULONG_MAX, \
              s8: CHAR_MAX, \
              s16: SHRT_MAX, \
              s32: INT_MAX, \
              s64: LONG_MAX,        \
              f32: FLT_MAX          \
              f64: DBL_MAX)

#define DTYPE_MIN(type_) Generic((type_), \
              u8: 0, \
              u16: 0, \
              u32: 0, \
              u64: 0ULL, \
              s8: CHAR_MIN, \
              s16: SHRT_MIN, \
              s32: INT_MIN, \
              s64: LONG_MIN,        \
              f32: FLT_MIN          \
              f64: DBL_MIN)


#define OP_GEN_ADD(type_) \
  TEENYML_EXPORT type_ tml__op_add(type_ a, type_ b) {return a + b;}

#define OP_GEN_SUB(type_) \
  TEENYML_EXPORT type_ tml__op_sub(type_ a, type_ b) {return a - b;}

#define OP_GEN_MUL(type_) \
  TEENYML_EXPORT type_ tml__op_mul(type_ a, type_ b) {return a * b;}

#define OP_GEN_DIV(type_) \
  TEENYML_EXPORT type_ tml__op_div(type_ a, type_ b) {return a / b;}

#define OP_GEN_MIN(type_) \
  TEENYML_EXPORT type_ tml__op_min(type_ a, type_ b) {return a < b ? a : b;}

#define OP_GEN_MAX(type_) \
  TEENYML_EXPORT type_ tml__op_max(type_ a, type_ b) {return a > b ? a : b;}

#define OP_GEN_NEG(type_) \
  TEENYML_EXPORT type_ tml__op_neg(type_ a) {return ZERO(a) - a;}

#define OP_GEN_ELEMWISE(type_) \
  OP_GEN_ADD(type_)            \
  OP_GEN_SUB(type_)            \
  OP_GEN_MUL(type_)            \
  OP_GEN_DIV(type_)            \
  OP_GEN_MIN(type_)            \
  OP_GEN_MAX(type_)            \
  OP_GEN_NEG(type_)

OP_GEN_ELEMWISE(u8)
OP_GEN_ELEMWISE(u16)
OP_GEN_ELEMWISE(u32)
OP_GEN_ELEMWISE(u64)
OP_GEN_ELEMWISE(u128)
OP_GEN_ELEMWISE(s8)
OP_GEN_ELEMWISE(s16)
OP_GEN_ELEMWISE(s32)
OP_GEN_ELEMWISE(s64)
OP_GEN_ELEMWISE(s128)
OP_GEN_ELEMWISE(f32)
OP_GEN_ELEMWISE(f64)

#define OP_GEN_LAYER_A_B_DEST(rank_, type_, op_) \
  TEENYML_EXPORT void tml_op_##op_(type_ dest, type_ a, type_ b) {return a < b ? a : b;}


#endif //TEENYML_TEENYML_OPS_PRIV_H
