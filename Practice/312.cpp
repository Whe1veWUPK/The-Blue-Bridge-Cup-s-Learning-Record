#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=360,M=50;
int s[N],c[5];
int n,m;
int dp[M][M][M][M];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&s[i]);
	}
	for(int i=0;i<m;++i){
		int x;
		scanf("%d",&x);
		++c[x];
	}
	dp[0][0][0][0]=s[1];
	for(int A=0;A<=c[1];++A){
		for(int B=0;B<=c[2];++B){
			for(int C=0;C<=c[3];++C){
				for(int D=0;D<=c[4];++D){
					int score=s[1+A+2*B+3*C+4*D];
					int&v=dp[A][B][C][D];
					if(A){
						v=max(v,dp[A-1][B][C][D]+score);
					}
					if(B){
						v=max(v,dp[A][B-1][C][D]+score);
					}
					if(C){
						v=max(v,dp[A][B][C-1][D]+score);
					}
					if(D){
						v=max(v,dp[A][B][C][D-1]+score); 
					}
				}
			}
		}
	}
	printf("%d\n",dp[c[1]][c[2]][c[3]][c[4]]);
	return 0;
}