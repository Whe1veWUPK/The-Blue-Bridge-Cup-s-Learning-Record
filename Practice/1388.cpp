#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110;
int w[N];
int dp[N][N];
int n;
int main(){
	scanf("%d",&n);
	
	int sum=0;
	for(int i=0;i<n;++i){
		scanf("%d",&w[i]);
		sum+=w[i];
	}
	for(int len=1;len<=n;++len){
		for(int i=0;i+len-1<n;++i){
			int j=i+len-1;
			if(j>=0){
			
			   dp[i][j]=max(w[i]-dp[i+1][j],w[j]-dp[i][j-1]);
			}
		    else{
		    	dp[i][j]=w[i]-dp[i+1][j];
			}
		}
	}
	int d=dp[0][n-1];
	int a=d+sum>>1;
	int b=sum-d>>1;
	printf("%d %d\n",a,b);
	return 0;
	
} 