#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>


using namespace std;
typedef long long LL;
const int N=1010;
int p[N];
struct Sphere{
   int x,y,z;
}q[N];
int t;
int n,h,r;
int find(int x){
	if(p[x]!=x){
		return find(p[x]);
	}
	return p[x];
}
int main(){
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		
		scanf("%d%d%d",&n,&h,&r);
		for(int j=0;j<=n+1;++j){
			p[j]=j;
		}
		for(int j=1;j<=n;++j){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			q[j]={x,y,z};
			if(abs(z-0)<=r){
				p[find(j)]=find(0);
			}
			if(abs(z-h)<=r){
				p[find(j)]=find(n+1);
			}
		}

		
		for(int j=1;j<=n;++j){
			for(int k=1;k<j;++k){
				LL dx=abs(q[j].x-q[k].x);
				LL dy=abs(q[j].y-q[k].y);
				LL dz=abs(q[j].z-q[k].z);
				LL dis=dx*dx+dy*dy+dz*dz;
				if(dis<=4*(LL)r*r){
					p[find(j)]=find(k);
				} 
			}
		}


		if(find(0)==find(n+1)){
			puts("Yes");
		}
		else{
			puts("No");
		}
		
	}
	return 0;
}