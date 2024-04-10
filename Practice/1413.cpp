#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N=3010;
int s[N][N],h[N][N];
int R,c,p;
int top;
int stk[N];
int l[N],r[N];
int work(int h[]){
	h[0]=-1;
	h[c+1]=-1;
    top=0;
    stk[++top]=0;
    for(int i=1;i<=c;++i){
    	while(h[stk[top]]>=h[i]){
    		--top;
		}
		l[i]=stk[top];
		stk[++top]=i;
	}
	top=0;
    stk[++top]=c+1;
    for(int i=c;i>=1;--i){
    	while(h[stk[top]]>=h[i]){
    		--top;
		}
		r[i]=stk[top];
		stk[++top]=i;
	}
	
	int res=0;
	for(int i=1;i<=c;++i){
		res=max(res,h[i]*(r[i]-l[i]-1));
	}
	return res;
}
int main(){
	scanf("%d%d%d",&R,&c,&p);
    while(p--){
    	int x, y;
    	scanf("%d%d",&x,&y);
    	s[x][y]=1;
    	
	}
	for(int i=1;i<=R;++i){
		for(int j=1;j<=c;++j){
			if(!s[i][j]){
				h[i][j]=h[i-1][j]+1;
			}
		}
	}
	int res=0;
	for(int i=1;i<=R;++i){
		res=max(res,work(h[i]));
	}
	printf("%d\n",res);
	return 0; 
}