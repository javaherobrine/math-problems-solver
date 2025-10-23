#include<iostream>
#include<string>
#include<algorithm>
#include"int128.h"
using namespace jaro;
using namespace std;
using ll=long long;
ostream& operator <<(ostream& lhs,int128 rhs){
	int128 ZERO{0ULL,0ULL};
	string s;
	while(jaro::less(ZERO,rhs)){
		//cerr<<rhs.highbit<<" "<<rhs.lowbit<<endl;
		s+='0'+modulo(rhs,10);
		rhs=divide(rhs,10);
	}
	reverse(s.begin(),s.end());
	return lhs<<s;
}
int main(){
//	Mat translation;
//	translation.mat.resize(4,vector<Poly>(4));
//	Poly ONE{vector<Mono>{Mono{1}}};
//	translation[0][0]=ONE;
//	translation[1][1]=ONE;
//	translation[2][2]=ONE;
//	translation[3][3]=ONE;
//	Poly X{{{1,{{"x",1}}}}};
//	Poly Y{{{1,{{"y",1}}}}};
//	Poly Z{{{1,{{"z",1}}}}};
//	translation[0][3]=X;
//	translation[1][3]=Y;
//	translation[2][3]=Z;
//	Mat yaw;
//	yaw.mat.resize(4,vector<Poly>(4));
//	Poly ThetaC{{{1,{{"cos(yaw)",1}}}}};
//	Poly ThetaS{{{1,{{"sin(yaw)",1}}}}};
//	/*
//	 * (x+zi)(cos+isin)=(xcos-zsin)+(zcos+xsin)i
//	 */
//	yaw[0][0]=ThetaC;
//	yaw[0][2]=-ThetaS;
//	yaw[1][1]=ONE;
//	yaw[2][0]=ThetaS;
//	yaw[2][2]=ThetaC;
//	yaw[3][3]=ONE;
//	Mat pitch;
//	pitch.mat.resize(4,vector<Poly>(4));
//	Poly PhiC{{{1,{{"cos(pitch)",1}}}}};
//	Poly PhiS{{{1,{{"sin(pitch)",1}}}}};
//	/*
//	 * (y+iz)(cos+isin)=(ycos-zsin)+(zcos+ysin)i
//	 */
//	pitch[0][0]=ONE;
//	pitch[1][1]=PhiC;
//	pitch[1][2]=PhiS;
//	pitch[2][1]=PhiS;
//	pitch[2][2]=PhiC;
//	pitch[3][3]=ONE;
//	cerr<<pitch*yaw*translation;
//	return 0;
	cout<<multiply_raw(1ULL<<60,1ULL<<9);
}
