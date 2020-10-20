#include <iostream>
template<int N>
class C{
  public:
    enum
    {
        value=1+ C<N-1>::value
    };
};

template<>
class C<1>{
  public:
    enum {
        value=1
    };
};
int main(){
    std::cout<<C<4>::value;
}
