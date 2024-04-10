#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=310;
char m[N][N];
int v[N][N];
int t;
int n;
void dfs(int a,int b){
	if(v[a][b]){
		v[a][b]=-1;
		return;
	}
	if(!v[a][b]){
		v[a][b]=-1;
		for(int i=a-1;i<=a+1;++i){
			for(int j=b-1;j<=b+1;++j){
				if(i==a&&j==b){
					continue;
				}
				if(i>=0&&i<n&&j>=0&&j<n){
					dfs(i,j);
				}
			}
		}
	}

	
}
int main(){
	scanf("%d",&t);
	for(int round=1;round<=t;++round){
		
		scanf("%d",&n);
		memset(v,0,sizeof v);
		for(int i=0;i<n;++i){
			scanf("%s",m[i]);
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(m[i][j]=='*') {
					v[i][j]=-1;
				}
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
                if(m[i][j]=='.'){
                		for(int a=i-1;a<=i+1;++a){
				            for(int b=j-1;b<=j+1;++b){
							    if(a>=0&&a<n&&b>=0&&b<n){
								    if(m[a][b]=='*'){
									    ++v[i][j];
								    }
							    }
						   }   
					    }  
				}
			}
		}

		int res=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(v[i][j]==0){
					++res;
					dfs(i,j);
				}
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(v[i][j]>0){
					++res;
				}
			}
		}
		printf("Case #%d: %d\n",round,res);
	}
	return 0;
} 