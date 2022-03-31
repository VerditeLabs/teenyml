#include "teenyml.h"
#include "teenyml_macromagic_priv.h"


#ifndef T
#error "T must be defined for tensor generation, e.g. u8, f32"
#endif

#ifndef RANK
#error "RANK must be defined for tensor generation, e.g. 1,2,3"
#endif

#ifndef TENSOR
#error "TENSOR must be defined for tensor generation, e.g. tml_tensor1_f32_t"
#endif

#ifndef DIMS
#error "DIMS must be defined to match tensor generation e.g. tml_dims2_t for tml_tensor2_*_t"
#endif

struct TENSOR(RANK, T) {
    u64 tag;
    struct DIMS(RANK) extent;
    T data[];             
  }; 
  TEENYML_EXPORT struct TENSOR(RANK, T)* TENSOR(RANK, T)(struct DIMS(RANK) extent){
    struct TENSOR(RANK,T)* ret =(struct TENSOR(RANK, T)*) malloc(sizeof(struct TENSOR(RANK,T)) + tml_dims2len(extent)*sizeof(T));
    ret->extent = extent; 
    return ret; 
  } 
  TEENYML_EXPORT s32 tml_rank(struct TENSOR(RANK, T)* tensor){ return RANK; }
  TEENYML_EXPORT T tml_get(struct TENSOR(RANK, T)* tensor, struct DIMS(RANK) idx) { return tensor->data[tml_idx(tensor->extent, idx)]; }
  TEENYML_EXPORT T tml_get(struct TENSOR(RANK, T)* tensor, s32 idx) { return tensor->data[idx]; }
  TEENYML_EXPORT void tml_set(struct TENSOR(RANK, T)* tensor, struct DIMS(RANK) idx, T data) { tensor->data[tml_idx(tensor->extent, idx)] = data; }
  TEENYML_EXPORT void tml_set(struct TENSOR(RANK, T)* tensor, s32 idx, T data) { tensor->data[idx] = data; }
  TEENYML_EXPORT void tml_fill(struct TENSOR(RANK, T)* tensor, tml_fill_e fill) {
    switch (fill) {
    case FILL_TZERO:for (int _ = 0; _ < tml_dims2len(tensor->extent); _++) { 
      tml_set(tensor, _, ZERO(tensor->data[0])); 
    } break; 
    case FILL_TONES:for (int _ = 0; _ < tml_dims2len(tensor->extent); _++) { 
      tml_set(tensor, _, ONE(tensor->data[0])); 
    } break; 
    case FILL_TINC: for (int _ = 0; _ < tml_dims2len(tensor->extent); _++) { 
      tml_set(tensor, _, (T)_); 
    } break; 
    case FILL_TDEC: for (int _ = 0; _ < tml_dims2len(tensor->extent); _++) { 
      tml_set(tensor, _, ZERO(tensor->data[0]) - (T)_); 
    }break; 
    case FILL_TRAND:break; 
    default: bail("invalid fill type"); break; 
    } 
  }