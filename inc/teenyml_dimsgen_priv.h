#include "teenyml.h"
#include "teenyml_macromagic_priv.h"

#ifndef T
#error "T must be defined for dims generation, e.g. u8, f32"
#endif

#ifndef RANK
#error "RANK must be defined for dims generation, e.g. 1,2,3"
#endif

struct DIMS(RANK) {
  s32 raw[MAX_DIMS]; 
  struct {s32 __VA_ARGS__;}; 
}; 
TEENYML_EXPORT struct DIMS(RANK) DIMS(RANK) (s32 dims[static RANK]){
  struct DIMS(RANK) ret;
  memcpy(ret.raw, dims, RANK * sizeof(s32));
  return ret;
} 
TEENYML_EXPORT struct DIMS(RANK) TML__M_CONCAT2(DIMS(RANK), _null) (void){
  return (struct DIMS(RANK)){.raw={TML__REPEAT(RANK,0)}};
} 
TEENYML_EXPORT struct DIMS(RANK) DIMS(RANK) (struct DIMS(RANK) dims){
  struct DIMS(RANK) ret;
  memcpy(ret.raw, dims.raw, RANK * sizeof(s32));
  return ret;
} 
TEENYML_EXPORT s32 tml_rank(struct DIMS(RANK) dims){ return RANK; }
TEENYML_EXPORT s32 tml_idx(struct DIMS(RANK) extent, struct DIMS(RANK) idx){
  s32 i = 0, sz = 1; 
  for(s32 _ = RANK - 1; _ >= 0; _--) {
    i += idx.raw[_]*sz; sz*=extent.raw[_]; 
  } 
  return i;
}                               
TEENYML_EXPORT struct DIMS(RANK) tml_idx(struct DIMS(RANK) extent, s32 idx){
  s32 _ret[RANK] = {0};                              
  s32 sz = 1; 
  for(s32 _ = RANK - 1; _ >= 0; _--) {
    sz*=extent.raw[_];  
    _ret[_] = idx % sz; 
  } 
  return DIMS(RANK)(_ret);
} 
TEENYML_EXPORT s32 tml_dims2len(struct DIMS(RANK) dims) {
  s32 ret = 1; 
  for(int i = 0; i < RANK; i++) ret*= dims.raw[i]; 
  return ret; 
}