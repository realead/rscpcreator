#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

#define RSCP_CHECK
#include <rscp/details/creator_details.h>


size_t encode(const std::vector<size_t> &vec){
  size_t res=0;
  size_t n=vec.size();
  for(const auto &v : vec){
    res=res*n+v;
  }
  return res;
}

std::map<size_t, size_t> single_cycle_counts(size_t n){
    std::vector<size_t> vec(n);
    for(size_t i=0;i<n;i++){
        vec[i]=i;
    }

    std::map<size_t, size_t> map;
    std::vector<size_t> res(n);
    std::vector<size_t> iperm(n);
    do {
       rscp::details::cyclic_from_permutation(vec, iperm, res);
       map[encode(res)]++;
    } while ( std::next_permutation(vec.begin(), vec.end()) );

    return map;
}


int main(){

  //header:
  std::cout<<"N,PERM_ID,CNT\n";
  for(size_t i=3;i<10;i++){
       auto map=single_cycle_counts(i);

       //output:
       size_t cnt=0;
       for(const auto &val : map){
         std::cout<<i<<","<<cnt<<","<<val.second<<"\n";
         cnt++;
       }
  }
}
  
