#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=16,M=1<<N;
double p[N],f[M][5*N+1];
int n,k;
double dp(int s,int c,int r){
	double&v=f[s][c];
	if(v>=0){
		return v;
	}
	if(c>=r*k){
		return v=0;
	}
	v=0;
	for(int i=0;i<n;++i){
		if(s>>i&1){
			v+=p[i]*(dp(s,c+1,r)+1);
		}
		else{
			v+=p[i]*(dp(s|(1<<i),c,r-1)+1);
		}
	}
	return v;
	
	
	
}
int main(){
	scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
    	scanf("%lf",&p[i]);
	}
	memset(f,-1,sizeof f);
	
	printf("%.10lf\n",dp(0,0,n));
	return 0;
}