#pragma once
#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED
#include<vector>
#include<iostream>
namespace jaro{
template<typename NumType>
	struct Matrix{
		std::vector<std::vector<NumType>> mat;
		std::vector<NumType> operator [] (const std::size_t& i){
			return mat[i];
		}
		const std::vector<NumType> operator [] (const std::size_t& i) const{
			return mat[i];
		}
	};
	template<typename NumType>
	Matrix<NumType> operator * (const Matrix<NumType>& lhs, const Matrix<NumType>& rhs){
		std::size_t m,p,n;
		p=lhs[0].size();
		if(p!=rhs.mat.size()){
			std::cerr<<"Illegal argument";
			return;
		}
		m=lhs.mat.size();
		n=rhs[0].size();
		Matrix<NumType> result;
		result.mat.resize(m,std::vector<NumType>(n));
		for(std::size_t i=0;i<m;++i){
			for(std::size_t j=0;j<n;++j){
				for(std::size_t k=0;k<p;++k){
					result[i][j]+=lhs[i][k]*rhs[k][j];
				}
			}
		}
		return result;
	}
	template<typename NumType>
	std::ostream& operator << (std::ostream& lhs, const Matrix<NumType>& rhs){
		for(std::size_t i=0;i<rhs.mat.size();++i){
			for(std::size_t j=0;j<rhs.mat[i].size();++j){
				lhs<<"line "<<i<<", "<<"column "<<j<<"= "<<rhs[i][j]<<"\n";
			}
		}
		return lhs<<std::flush;
	}
}
#endif
