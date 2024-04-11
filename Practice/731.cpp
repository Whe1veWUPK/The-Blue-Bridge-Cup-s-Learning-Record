#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=20,INF=0x3f3f3f3f,M=1<<N;
int c[N][N],f[M][N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
    	for(int j=0;j<n;++j){
    		scanf("%d",&c[i][j]);
		}
	}
	memset(f,INF,sizeof f);
	f[1][0]=0;
	for(int i=1;i<1<<N;i+=2){
		for(int j=0;j<n;++j){
			if((i>>j)&1){
			    for(int k=0;k<n;++k){
			    	if(((i-(1<<j))>>k)&1){			    		
						f[i][j]=min(f[i][j],f[i-(1<<j)][k]+c[k][j]);
			        }
				}
			}
		}
	}
	int res=INF;
	for(int i=1;i<n;++i){
		res=min(res,f[(1<<n)-1][i]+c[i][0]);
	} 
	printf("%d\n",res); 
	
	
	return 0;
}