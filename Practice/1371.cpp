#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N=10010,M=30;
int n,m;
LL f[M][N];
int v[M];
int main(){
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
    	scanf("%d",&v[i]);
	}
	f[0][0]=1;
    for(int i=1;i<=n;++i){
    	for(int j=0;j<=m;++j){
    		f[i][j]=f[i-1][j];
    		if(j>=v[i]){
    			f[i][j]+=f[i][j-v[i]];
			}
		}
	}
	printf("%lld\n",f[n][m]);
	return 0;
}