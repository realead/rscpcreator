#include <random>
#include <vector>
#include <iostream>

#include <rscp/creator.h>


int main(){
  rscp::creator<int> creator(10, std::mt19937(1000));
  std::vector<int> vec(10);
  creator.next(vec);
  for(auto &v : vec){
     std::cout<<v<<" ";
  }
}
