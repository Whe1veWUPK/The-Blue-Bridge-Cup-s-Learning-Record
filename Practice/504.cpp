#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long LL;


int quickPower(int a,int b,int p){
	int res=1%p;
	while(b){
		if(b&1)res=(LL)res*a%p;
		b>>=1;
		
		a=(LL)a*a%p;
	}
	return res;
}

int main(){
	int n,m,x,k;
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%lld",(x+((LL)m*quickPower(10,k,n)))%n);
	return 0; 
}