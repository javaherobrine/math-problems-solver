#ifndef STAT_HPP
#define STAT_HPP
#include<vector>
#include<utility>
#include<cmath>
template<typename T>
T avarage(const std::vector<T>& input){
	T sum=0;
	for(auto&& i:input){
		sum+=i;
	}
	return sum/input.size();
}
template<typename T>
T u(const std::vector<T>& input){
	T avg=avarage(input);
	T sum=0;
	for(auto&& i:input){
		sum+=std::pow(i-avg,2);
	}
	T size=input.size();
	size*=size-1;
	return std::sqrt(sum/size);
}
template<typename T>
std::pair<T,T> congression(const std::vector<std::pair<T,T>>& input){
	T x=0,y=0;
	for(auto&& [i,j]:input){
		x+=i;
		y+=j;
	}
	x/=input.size();
	y/=input.size();
	T n1=0,n2=0;
	for(auto&& [i,j]:input){
		n1+=(i-x)*(j-y);
		n2+=pow(i-x,2);
	}
	T b=n1/n2;
	return {b,y-b*x};
}
#endif
