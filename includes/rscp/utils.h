#pragma once

#include <vector>


//--------------- Interface:

namespace rscp{
    template<typename T>
    bool is_permutation(const std::vector<T> &perm);

    template<typename T>
    bool is_single_cycle(const std::vector<T> &perm);
}


//-------------- Implementation:

template<typename T>
bool  rscp::is_permutation(const std::vector<T> &perm){
   auto size=perm.size();
   std::vector<bool> set(size, false);
   for(const auto &v :perm){
        if(set.at(v))
            return false;
        set.at(v)=true;
   }
   return true;
}

template<typename T>
bool rscp::is_single_cycle(const std::vector<T> &perm){
   size_t number_of_steps=perm.size()-1;
   T current=perm.at(0);
   for(size_t i=0;i<number_of_steps;i++){
        if(current==0)
            return false;
        current=perm.at(current);
   }
   return current==0;
}

