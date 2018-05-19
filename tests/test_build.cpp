#include <random>
#include <vector>
#include <iostream>
#include <cassert>

#define RSCP_CHECK
#include <rscp/creator.h>
#include <rscp/utils.h>


int main(){
  rscp::creator<int> creator(10, std::mt19937(1000));
  std::vector<int> vec(10);

  std::cout<<"Is permutation: "<<(rscp::is_permutation(vec)?"YES":"NO")<<"\n";
  creator.next(vec);
  for(auto &v : vec){
     std::cout<<v<<" ";
  }
  std::cout<<"\nIs permutation: "<<(rscp::is_permutation(vec)?"YES":"NO")<<"\n";
  std::cout<<"Is single cycle: "<<(rscp::is_single_cycle(vec)?"YES":"NO")<<"\n";

  //check functionality of is_single_cycle
  assert(rscp::is_single_cycle(std::vector<int>{1,2,0}));
  assert(!rscp::is_single_cycle(std::vector<int>{0,2,1}));
  assert(!rscp::is_single_cycle(std::vector<int>{1,2,1}));
}
  
