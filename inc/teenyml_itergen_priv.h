#include "teenyml.h"
#include "teenyml_macromagic_priv.h"

#ifndef T
#error "T must be defined for dims generation, e.g. u8, f32"
#endif

#ifndef RANK
#error "RANK must be defined for dims generation, e.g. 1,2,3"
#endif


struct ITER(RANK) {
  s32 idx;
  union TENSOR_nodtype(RANK)* tensor;
};
TEENYML_EXPORT struct ITER(RANK) ITER(RANK)(union TENSOR_nodtype(RANK)* tensor ) {
  struct ITER(RANK) ret;
  ret.idx = 0;
  ret.tensor = tensor;
  return ret;
}
TEENYML_EXPORT bool tml_iter_next(struct ITER(RANK)* iter) {
  /* for now we'll just support 0 .. len, lowest -> highest rank. */
  /* TODO: allow for dim incrementing order by passing arr {3,1,2...} to allow this */
  return ++iter->idx != tml_dims2len(iter->tensor->extent);
}