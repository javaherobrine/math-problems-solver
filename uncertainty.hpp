#ifndef UNCERTAINTY_HPP
#define UNCERTAINTY_HPP
#include"stat.hpp"
#include"function.hpp"
#include<cmath>
template<typename T>
inline T typeA(std::vector<T> input){
	size_t n=input.size();
	T avg=avarage(input);
	T sum2=0;
	for(auto&& ref:input){
		sum2+=ref*ref;
	}
	sum2-=n*avg*avg;
	return std::sqrt(sum2/(n-1));
}
template<typename T>
inline T compose(std::vector<T> input){
	T sum=0;
	for(auto&& i:input){
		sum+=i*i;
	}
	return std::sqrt(sum);
}
template<typename T>
inline T uncertainty(T(*fp)(std::vector<T>), std::vector<T> results, std::vector<T> uncertainties, T h){
	size_t n=results.size();
	for(size_t i=0;i<n;++i){
		uncertainties[i]*=partialDifferential(fp,results,h,i);
	}
	return compose(uncertainties);
}
#endif
