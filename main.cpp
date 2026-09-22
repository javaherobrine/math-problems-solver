#include<iostream>
#include<vector>
#include"stat.hpp"
#include"matrix.hpp"
#include"poly.hpp"
using namespace jaro;
using namespace std;
using ll=long long;
using Mono=Monomial<ll>;
using Poly=Polynomial<ll>;
using Mat=Matrix<Poly>;
int main(){
	Mat translation;
	translation.mat.resize(4,vector<Poly>(4));
	Poly ONE{vector<Mono>{Mono{1}}};
	translation[0][0]=ONE;
	translation[1][1]=ONE;
	translation[2][2]=ONE;
	translation[3][3]=ONE;
	Poly X{{{1,{{"x",1}}}}};
	Poly Y{{{1,{{"y",1}}}}};
	Poly Z{{{1,{{"z",1}}}}};
	X=-X;
	Y=-Y;
	Z=-Z;
	translation[0][3]=X;
	translation[1][3]=Y;
	translation[2][3]=Z;
	Mat yaw;
	yaw.mat.resize(4,vector<Poly>(4));
	Poly ThetaC{{{1,{{"cos(yaw)",1}}}}};
	Poly ThetaS{{{1,{{"sin(yaw)",1}}}}};
	/*
	 * (x+zi)(cos+isin)=(xcos-zsin)+(zcos+xsin)i
	 * cos 0 -sin 0
	 * 0 1 0 0
	 * sin 0 cos 0
	 * 0 0 0 1
	 */
	yaw[0][0]=ThetaC;
	yaw[0][2]=-ThetaS;
	yaw[1][1]=ONE;
	yaw[2][0]=ThetaS;
	yaw[2][2]=ThetaC;
	yaw[3][3]=ONE;
	Mat pitch;
	pitch.mat.resize(4,vector<Poly>(4));
	Poly PhiC{{{1,{{"cos(pitch)",1}}}}};
	Poly PhiS{{{1,{{"sin(pitch)",1}}}}};
	/*
	 * (y+iz)(cos+isin)=(ycos-zsin)+(zcos+ysin)i
	 * 1 0 0 0
	 * 0 cos -sin 0
	 * 0 sin cos 0
	 * 0 0 0 1
	 */
	pitch[0][0]=ONE;
	pitch[1][1]=PhiC;
	pitch[1][2]=PhiS;
	pitch[2][1]=-PhiS;
	pitch[2][2]=PhiC;
	pitch[3][3]=ONE;
	cerr<<pitch*yaw*translation;
	return 0;
//	vector<double> T2{1.608*1.608,1.5047*1.5047,1.407*1.407,1.2913*1.2913,1.165*1.165,0.9979*0.9979};
//	vector<pair<double,double>> P{{1.608*1.608,(62.96+2.19)/100},{1.5047*1.5047,(55.03+2.19)/100},{1.407*1.407,(48.49+2.19)/100},{1.2913*1.2913,(40.08+2.19)/100},{1.165*1.165,(32.33+2.19)/100},{0.9979*0.9979,(23.5+2.19)/100}};
//	auto&& [k,b]=congression(P);
//	cerr<<k<<" "<<b<<endl;
//	cerr<<computeV2(congression(P),P)<<endl<<sqrt(computeS2(T2));
}
