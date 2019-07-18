#ifndef TYPELIST_SAMPLE_HPP_
#define TYPELIST_SAMPLE_HPP_
struct emptyType{};

template<typename T0=emptyType,typename T1=emptyType,typename T2=emptyType,typename T3=emptyType>
struct typelist{
  typedef T0 head;
  typedef typelist<T1,T2,T3> tail;
  enum {size=tail::size+1};
  enum {empty=false};
};
template<>
struct typelist<emptyType, emptyType, emptyType, emptyType>{
  typedef emptyType head;
  enum {size=0};
  enum {empty=true};
};
#endif
