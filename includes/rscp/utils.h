#pragma once

#include <vector>


//--------------- Interface:

namespace rscp{
    template<typename T>
    bool is_permutation(const std::vector<T> &perm);
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
