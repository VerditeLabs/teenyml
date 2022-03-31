
#pragma once
#ifndef TEENYML_TEENYML_MACROMAGIC_PRIV_H
#define TEENYML_TEENYML_MACROMAGIC_PRIV_H


#define auto __auto_type

#define OVERLOADABLE __attribute__((overloadable))
#define CONST __attribute__((const))
#define PURE __attribute__((pure))
#define TEENYML_EXPORT OVERLOADABLE static inline

#define ANON_ARRAY(t, n, ...) (t[n]){__VA_ARGS__}


#define bail(...) do{printf("bailed at %d:%s:%s\n",__LINE__,__FUNCTION__,__FILE__); printf(__VA_ARGS__); exit(1);} while(0)

//TODO: generalize into a TML__M_CONCAT(...) macro
#define TML__M_CONCAT0()
#define TML__M_CONCAT1(A) TML__M_CONCAT1(A)
#define _TML__M_CONCAT1(A) A
#define TML__M_CONCAT2(A, B)   _TML__M_CONCAT2(A, B)
#define _TML__M_CONCAT2(A, B)   A ## B
#define TML__M_CONCAT3(A, B, C)   _TML__M_CONCAT3(A, B, C)
#define _TML__M_CONCAT3(A, B, C)   A ## B ## C

#define TML__M_CONCAT4(A, B, C, D)   _TML__M_CONCAT4(A, B, C, D)
#define _TML__M_CONCAT4(A, B, C, D)   A ## B ## C ## D

#define TML__M_CONCAT5(A, B, C, D, E)   _TML__M_CONCAT5(A, B, C, D, E)
#define _TML__M_CONCAT5(A, B, C, D, E)   A ## B ## C ## D ## E

#define TML__M_CONCAT6(A, B, C, D, E, F)   _TML__M_CONCAT6(A, B, C, D, E, F)
#define _TML__M_CONCAT6(A, B, C, D, E, F)   A ## B ## C ## D ## E ## F

#define TML__M_CONCAT7(A, B, C, D, E, F, G)   _TML__M_CONCAT7(A, B, C, D, E, F, G)
#define _TML__M_CONCAT7(A, B, C, D, E, F, G)   A ## B ## C ## D ## E ## F ## G

#define TML__M_CONCAT8(A, B, C, D, E, F, G, H)   _TML__M_CONCAT8(A, B, C, D, E, F, G, H)
#define _TML__M_CONCAT8(A, B, C, D, E, F, G, H)   A ## B ## C ## D ## E ## F ## G ## H

#define TML__M_CONCAT9(A, B, C, D, E, F, G, H, I)   _TML__M_CONCAT9(A, B, C, D, E, F, G, H, I)
#define _TML__M_CONCAT9(A, B, C, D, E, F, G, H, I)   A ## B ## C ## D ## E ## F ## G ## H ## I

#define TML__M_REPEAT_1(X) X
#define TML__M_REPEAT_2(X) X X
#define TML__M_REPEAT_3(X) X X X
#define TML__M_REPEAT_4(X) X X X X
#define TML__M_REPEAT_5(X) X X X X X
#define TML__M_REPEAT_6(X) X X X X X X
#define TML__M_REPEAT_7(X) X X X X X X X
#define TML__M_REPEAT_8(X) X X X X X X X X
#define TML__M_REPEAT_9(X) X X X X X X X X X

#define TML__M_EXPAND(...) __VA_ARGS__

#define TML__M_REPEAT__(N, X) TML__M_EXPAND(TML__M_REPEAT_ ## N)(X)
#define TML__M_REPEAT_(N, X) TML__M_REPEAT__(N, X)
#define TML__M_REPEAT(N, X) TML__M_REPEAT_(TML__M_EXPAND(N), X)

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


#endif //TEENYML_TEENYML_MACROMAGIC_PRIV_H
