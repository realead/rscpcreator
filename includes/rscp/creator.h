#pragma once

#include <vector>
#include <random>
#include <algorithm>

#ifdef RSCP_CHECK
  #include <cassert>
  #include "utils.h"
#endif

//--------------- Interface:

namespace rscp{

    //A factory for random single cycle permutations
    //
    //creator::next() returns a permutations of 0,...,n-1
    // 
    template<typename T, typename Generator=std::mt19937>
    class creator{
    private:
        Generator gen;
        std::vector<T> perm;
        std::vector<T> iperm;
    public:
        //custom generator:
        creator(size_t perm_size, Generator &&generator);

        //calculates next random single cycle permutation
        //and writes it into the result vector,
        //result must be at least perm_size big:
        void next(std::vector<T> &result);
    };
}



//-------------- Implementation:

template<typename T, typename Generator>
rscp::creator<T,Generator>::creator(size_t perm_size, Generator &&generator):
    perm(perm_size), iperm(perm_size), gen(generator)
{}


template<typename T, typename Generator>
void rscp::creator<T,Generator>::next(std::vector<T> &result)
{
    T SIZE=static_cast<T>(perm.size());
    for(T i=0;i<SIZE;i++)
        perm[i]=i;
   
    //Fisher-Yates
    for(T k=0;k<SIZE;k++){
      std::uniform_int_distribution<T> dis(k, SIZE-1);
      int for_swap=dis(gen);
      std::swap(perm[k], perm[for_swap]);
   }

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

