#ifndef INT_128_H
#define INT_128_H
#ifdef __cplusplus
namespace jaro{
extern "C"{
#endif
typedef struct int128{
	unsigned long long highbit;
	unsigned long long lowbit;
} int128;
unsigned long long highbit_raw(unsigned long long x){
	x|=x>>1;
	x|=x>>2;
	x|=x>>4;
	x|=x>>8;
	x|=x>>16;
	x|=x>>32;
	return x-(x>>1);
}
int128 plus(int128* a1,int128* a2){
	int128 a3;
	a3.lowbit=a1->lowbit+a2->lowbit;
	a3.highbit=a1->highbit+a2->highbit;
	if(a3.lowbit<=(a1->lowbit|a2->lowbit)){
		a3.highbit+=1;
	}
	return a3;
}
int128 minus(int128* a1,int128* a2){
	int128 a3;
	a3.highbit=a1->highbit-a2->highbit;
	a3.lowbit=a1->lowbit-a2->lowbit;
	if(a1->lowbit<a2->lowbit){
		a3.highbit-=1;
	}
	return a3;
}
int128 multiply(int128* a1,int128* a2){
	int128 a3;
	a3.highbit=a1->highbit*a2->lowbit+a1->lowbit*a2->highbit;//a1->highbit*a2->highbit will overflow
	return plus(&a3,multiply_raw(a1->lowbit,a2->lowbit));
}
int128 multiply_raw(unsigned long long a1,unsigned long long a2){
	int128 res;
	unsigned long long a1_low=a1&0xFFFFFFFF,a2_low=a2&0xFFFFFFFF;
	a1>>=32;
	a2>>=32;
	res.lowbit=a1_low*a2_low;
	res.highbit=a1*a2;
	unsigned long long temp=a1*a2_low+a2*a1_low;
	res.lowbit+=(temp&0xFFFFFFFF)<<32;
	res.highbit+=temp>>32;
	return res;
}
int128 divide(int128* a1,unsigned long long a2){
	int128 a3;
	a3.highbit=a1->highbit/a2;
	unsigned long long reminder=a1->highbit%a2;
	unsigned long long factor=highbit_raw(reminder)<<1;
	unsigned long long p=reminder*((1<<63)/factor)+a1->lowbit/factor;
	a3.lowbit=p/a2;
	p%=a2;
	p*=factor;
	p+=a1->lowbit&(factor-1);
	a3.lowbit+=p/a2;
	return a3;
}
unsigned long long modulo(int128* a1,unsigned long long a2){
	unsigned long long reminder=a1->highbit%a2;
	unsigned long long factor=highbit_raw(reminder)<<1;
	unsigned long long p=reminder*((1<<63)/factor)+a1->lowbit/factor;
	p%=a2;
	p*=factor;
	p+=a1->lowbit&(factor-1);
	return p%a2;
}
#ifdef __cplusplus
}
}
#endif
#endif
