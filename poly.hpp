#pragma once
#ifndef POLY_HPP_INCLUDED
#define POLY_HPP_INCLUDED
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
namespace jaro{
	template<typename NumType>
	struct Monomial{
		Monomial(NumType input){
			coefficient=input;
		}
		void operator *= (const Monomial<NumType>& rhs) {
			coefficient*=rhs.coefficient;
			for(auto iter=rhs.content.begin();iter!=rhs.content.end();++iter){
				content[iter->first]+=iter->second;
			}
		}
		bool operator < (const Monomial<NumType>& rhs){
			std::size_t s1=content.size(), s2=rhs.content.size();
			if(s1!=s2){
				return s1<s2;
			}
			auto iter0=content.begin(), iter1=rhs.content.begin();
			for(;iter0!=content.end();++iter0){
				if(iter0->first!=iter1->first){
					return iter0->first<iter1->first;
				}else if(iter0->second!=iter1->second){
					return iter0->second<iter1->second;
				}
				++iter1;
			}
			return coefficient<rhs.coefficient;
		}
		NumType coefficient;
		std::map<std::string,NumType> content;
	};
	template<typename NumType>
	void monomial_merge(std::vector<Monomial<NumType>>& vec){
		//I assume that vec has been sorted previously
		if(vec.empty()){
			return;
		}
		Monomial<NumType> s=vec[0];
		std::vector<Monomial<NumType>> result;
		for(std::size_t i=1;i<vec.size();++i){
			if(vec[i].content==s.content){
				s.coefficient+=vec[i].coefficient;
			}else{
				result.push_back(s);
				s=vec[i];
			}
		}
		result.push_back(s);
		vec=result;
	}
	template<typename NumType>
	Monomial<NumType> operator *(const Monomial<NumType>& lhs, const Monomial<NumType>& rhs){
		Monomial<NumType> copy{lhs};
		copy*=rhs;
		return copy;
	}
	template<typename NumType>
	std::ostream& operator << (std::ostream& lhs, const Monomial<NumType>& rhs){
		if(rhs.coefficient==0){
			return lhs<<0;
		}else if(rhs.coefficient==1){}
		else if(rhs.coefficient==-1){
			lhs<<'-';
		}else{
			lhs<<rhs.coefficient;
		}
		for(auto iter=rhs.content.begin();iter!=rhs.content.end();++iter){
			if(iter->second==1){
				lhs<<iter->first;
			}else{
				lhs<<"pow("<<iter->first<<","<<iter->second<<")";
			}
		}
		return lhs;
	}
	template<typename NumType>
	struct Polynomial{
		std::vector<Monomial<NumType>> content;
		void operator +=(const Polynomial& rhs){
			for(auto&& i:rhs.content){
				content.push_back(i);
			}
			monomial_merge(content);
		}
	};
	template<typename NumType>
	Polynomial<NumType> operator * (const Polynomial<NumType>& lhs, const Polynomial<NumType>& rhs){
		std::vector<Monomial<NumType>> vec;
		for(std::size_t i=0;i<lhs.content;++i){
			for(std::size_t j=0;j<rhs.content;++j){
				vec.push_back(lhs.content[i]*rhs.content[j]);
			}
		}
		sort(vec.begin(),vec.end());
		monomial_merge(vec);
		Polynomial<NumType> poly;
		poly.content=std::move(vec);
	}
	template<typename NumType>
	std::ostream& operator << (std::ostream& lhs, const Polynomial<NumType>& rhs){
		if(rhs.content.empty()){
			return lhs;
		}
		lhs<<rhs.content[0];
		for(std::size_t i=1;i<rhs.content.size();++i){
			Monomial<NumType> mono=rhs.content[i];
			if(mono.coefficient>0){
				lhs<<'+';
			}
			lhs<<mono;
		}
		return lhs;
	}
}
#endif
