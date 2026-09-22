#ifndef STAT_HPP
#define STAT_HPP
#include<vector>
#include<utility>
#include<cmath>
template<typename T>
inline T avarage(const std::vector<T>& input){
	T sum=0;
	for(auto&& i:input){
		sum+=i;
	}
	return sum/input.size();
}
template<typename T>
inline T u(const std::vector<T>& input){
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
inline std::pair<T,T> congression(const std::vector<std::pair<T,T>>& input){
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
template<typename T>
inline T computeV2(const std::pair<T,T>& equation,const std::vector<std::pair<T,T>>& input){
	auto&& [k,b]=equation;
	T result=0;
	for(auto&& [x,y]:input){
		T p=y-k*x-b;
		result+=p*p;
	}
	return result;
}
template<typename T>
inline T computeS2(const std::vector<T>& s){
	T result=0,avg=0;
	for(auto&& i:s){
		avg+=i;
	}
	avg/=s.size();
	for(auto&& i:s){
		T b=i-avg;
		result+=b*b;
	}
	return result/s.size();
}
#endif
