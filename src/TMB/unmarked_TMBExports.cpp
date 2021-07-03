#define TMB_LIB_INIT R_init_unmarked_TMBExports
#include <TMB.hpp>
#include <float.h>
#include "tmb_utils.hpp"
#include "tmb_pifun.hpp"
#include "tmb_keyfun.hpp"
#include "tmb_occu.hpp"
#include "tmb_pcount.hpp"
#include "tmb_multinomPois.hpp"
#include "tmb_distsamp.hpp"

template<class Type>
Type objective_function<Type>::operator() () {
  DATA_STRING(model);
  if(model == "tmb_occu") {
    return tmb_occu(this);
  } else if(model == "tmb_pcount") {
    return tmb_pcount(this);
  } else if(model == "tmb_multinomPois"){
    return tmb_multinomPois(this);
  } else if(model == "tmb_distsamp"){
    return tmb_distsamp(this);
  } else {
    error("Unknown model.");
  }
  return 0;
}
