#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include<vector>
template<typename T>
inline T partialDifferential(T(*fp)(std::vector<T>), std::vector<T> input, T h, std::size_t index){
	input[index]+=h;
	T s1=fp(input);
	h*=2;
	input[index]-=h;
	T s2=fp(input);
	return (s1-s2)/h;
}
#endif
