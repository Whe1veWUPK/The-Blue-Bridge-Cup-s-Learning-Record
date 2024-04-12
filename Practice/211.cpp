#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int M=10007,N=1010;
int C[N][N];
int a,b,k,n,m;
int main(){
    cin>>a>>b>>k>>n>>m;
	for(int i=0;i<=k;++i){
		for(int j=0;j<=i;++j){
			if(!j){
				C[i][j]=1;
			}
			else{
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
			}
		}
	}	
	int res=C[k][n];

	a%=M,b%=M;
	for(int i=0;i<n;++i){
		res=res*a%M;
	}
	for(int i=0;i<m;++i){
		res=res*b%M;
	}
	printf("%d\n",res);
	return 0;
} 