#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=110,M=30,Q=200;
const double eps=1e-8;
char s[N][N];
PII g[Q];
double hash_value[M];
int top,cnt;
int n,m;
void dfs(int a,int b){
	g[top++]={a,b};
	s[a][b]='0';
	
	for(int x=a-1;x<=a+1;++x){
		for(int y=b-1;y<=b+1;++y){
			if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='1'){
				dfs(x,y);
			}
		}
	}
}
double get_dist(PII& a,PII&b){
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
double get_hashV(){
	double sum=0;
	for(int i=0;i<top;++i){
		for(int j=0;j<i;++j){
			sum+=get_dist(g[i],g[j]);
		}
	}
	return sum;
}
char get_char(){
	double value=get_hashV();
	for(int i=0;i<cnt;++i){
		if(abs(hash_value[i]-value)<eps){
			return 'a'+i;
		}
	}
	hash_value[cnt++]=value;
	return 'a'+cnt-1;
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;++i){
		scanf("%s",s[i]);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(s[i][j]=='1'){
				top=0;
				dfs(i,j);
				char id=get_char();
				for(int k=0;k<top;++k){
					s[g[k].x][g[k].y]=id;
				}
			}
		}
	}
	for(int i=0;i<n;++i){
		puts(s[i]);
	}
	return 0;
}