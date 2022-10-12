//author: Java_Herobrine
#include<bits/stdc++.h>
using namespace std;
struct Matrix;
struct Vector;
struct Matrix{
	vector<vector<int>> mat;
	void transpose(){
		size_t s=mat[0].size();
		vector<vector<int>> answer(s,vector<int>(mat.size(),0));
		for(size_t i=0;i<mat.size();i++){
			for(size_t j=0;j<s;j++){
				answer[j][i]=mat[i][j];
			}
		}
		mat=move(answer);
	}
	void operator *=(const Matrix& rhs){
		size_t m=mat.size();
		size_t n=mat[0].size();
		size_t p=rhs.mat[0].size();
		vector<vector<int>> answer(n,vector<int>(p,0));
		for(size_t i=0;i<m;i++){
			for(size_t j=0;j<p;j++){
				for(size_t k=0;k<n;k++){
					answer[i][j]+=mat[i][k]*rhs.mat[k][j];
				}
			}
		}
		mat=move(answer);
	}
	void operator *=(const int& rhs){
		for(vector<int> v:mat){
			for(auto iter=v.begin();iter!=v.end();iter++){
				(*iter)*=rhs;
			}
		}
	}
	void operator +=(const Matrix& rhs){
		for(size_t i=0;i<mat.size();i++){
			for(size_t j=0;j<mat.size();j++){
				mat[i][j]+=rhs.mat[i][j];
			}
		}
	}
	Matrix operator *(const Matrix& rhs){
		Matrix m=*this;
		m*=rhs;
		return m;
	}
};
struct Vector{
	vector<int> vec;
	bool line;
	size_t length(){
		return vec.size();
	}
	void transpose(){
		line=!line;
	}
	Vector(vector<int>& v,bool l=false){
		vec=v;
		line=l;
	}
};
