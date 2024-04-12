#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int N=10010;

vector<int>ne[N];
int son[N];
bool st[N];
int n;
int dfs(int u){
	int res=0;

	son[u]=-1;

	for(int i=0;i<ne[u].size();++i){
		int x=ne[u][i];
        int d=dfs(x);
		if(d>res||(d==res&&x<son[u])){
			res=d;
			son[u]=x;
		}	 

	
		
	}
	return res+1;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int cnt;
		scanf("%d",&cnt);
		while(cnt--){
			int x;
			scanf("%d",&x);
			ne[i].push_back(x);
			st[x]=true;
		}
	}
	int root=0;
	while(st[root]){
		++root;
	}

	int res=dfs(root);
	printf("%d\n",res);
	printf("%d",root);
	int cur=root; 
	for(int i=0;i<res-1;++i){
		printf(" %d",son[cur]);
		cur=son[cur];
	}
	return 0; 
	
}