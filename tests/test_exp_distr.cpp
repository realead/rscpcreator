#include <random>
#include <vector>
#include <iostream>
#include <cassert>
#include <map>

#define RSCP_CHECK
#include <rscp/creator.h>
#include <rscp/utils.h>

size_t encode(const std::vector<size_t> &vec){
  size_t res=0;
  size_t n=vec.size();
  for(const auto &v : vec){
    res=res*n+v;
  }
  return res;
}

std::map<size_t, size_t> init_single_cycle_counts(size_t n){
    std::vector<size_t> vec(n);
    for(size_t i=0;i<n;i++){
        vec[i]=i;
    }

    std::map<size_t, size_t> result;
    do {
       if(rscp::is_single_cycle(vec)){
            result[encode(vec)]=0;
       }
    } while ( std::next_permutation(vec.begin(), vec.end()) );

    return result;
}


const size_t FACTOR=10;
int main(){

  //header:
  std::cout<<"N,PERM_ID,CNT\n";
  for(size_t i=3;i<10;i++){
       std::vector<size_t> vec(i);
       rscp::creator<size_t> creator(i, std::mt19937(1000));

       auto map=init_single_cycle_counts(i);
       const size_t size=map.size();

       //experiments:
       for(size_t cnt=0;cnt<FACTOR*size;cnt++){
         creator.next(vec);
         map[encode(vec)]++;
       }

       //output:
       size_t cnt=0;
       for(const auto &val : map){
         std::cout<<i<<","<<cnt<<","<<val.second<<"\n";
         cnt++;
       }
  }
}
  
