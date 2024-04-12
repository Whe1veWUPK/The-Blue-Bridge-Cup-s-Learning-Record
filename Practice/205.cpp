#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int M=10000;
int n;
void mul(int a[][2],int b[][2]){
	int c[2][2];
	memset(c,0,sizeof c);
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%M;
			}
		}
	}
	memcpy(a,c,sizeof c);
}
int fib(int x){
	int a[2][2]={0,1,0,0};
	int v[2][2]={0,1,1,1};
	while(x){
		if(x&1){
			mul(a,v);
		}
		x>>=1;
		mul(v,v);
	}
	
	return a[0][0];
}
int main(){
	while(cin>>n,n!=-1){
		cout<<fib(n)<<endl;
	}
	return 0;
} 
