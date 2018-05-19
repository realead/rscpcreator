#include <random>
#include <vector>
#include <iostream>

#include <rscp/creator.h>
#include <rscp/utils.h>


int main(){
  rscp::creator<int> creator(10, std::mt19937(1000));
  std::vector<int> vec(10);

  std::cout<<"Is permuation: "<<(rscp::is_permutation(vec)?"YES":"NO")<<"\n";
  creator.next(vec);
  for(auto &v : vec){
     std::cout<<v<<" ";
  }
  std::cout<<"\nIs permuation: "<<(rscp::is_permutation(vec)?"YES":"NO")<<"\n";
}
