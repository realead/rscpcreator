#pragma once

#include <vector>

#ifdef RSCP_CHECK
  #include <cassert>
  #include "../utils.h"
#endif


//--------------- Interface:

namespace rscp{
  namespace details{
       template<typename T>
       void cyclic_from_permutation(const std::vector<T> &perm, std::vector<T> iperm, std::vector<T> &result);
  }
}


//------------- Implementation
template<typename T>
void rscp::details::cyclic_from_permutation(const std::vector<T> &perm, std::vector<T> iperm, std::vector<T> &result)
{
   T SIZE=static_cast<T>(perm.size());

   //inverse:
   for(T i=0;i<SIZE;i++){
      iperm[perm[i]]=i;
   }

   //result=P^{-1}*Shift*P
   for(T i=0;i<SIZE;i++){
      T ii=perm[i]+1;
      if(ii==SIZE)//mod SIZE
         ii=0;
      result[i]=iperm[ii];
   } 

   //sanity check:
   #ifdef RSCP_CHECK
      assert(rscp::is_permutation(result));
      assert(rscp::is_single_cycle(result));
   #endif
}
