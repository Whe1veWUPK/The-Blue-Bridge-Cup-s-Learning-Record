#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=15010,M=32010;
int tr[M];
int ans[N];
int n;
int lowbit(int x){
	return x&-x;
}
int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){
		res+=tr[i];
	}
	return res;
}
void add(int x,int v){
	for(int i=x;i<M;i+=lowbit(i)){
		tr[i]+=v;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		++x;
		int t=query(x);
		++ans[t];
		add(x,1);
	}
	for(int i=0;i<n;++i){
		printf("%d\n",ans[i]);
	}
} 