#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=21;

int A,B,C;
struct Node{
	int a,b,c;
}n[N*N*N];

bool st[N][N][N];
void bfs(){
	int front=0,rear=0;
	n[0]={0,0,C};
	st[0][0][C]=true;
	int W[3]={A,B,C};
	while(front<=rear){
	    auto t=n[front++];

	    for(int i=0;i<3;++i){
	    	for(int j=0;j<3;++j){
	    		if(i!=j){
	    			int w[3]={t.a,t.b,t.c};
	    			int m=min(W[j]-w[j],w[i]);
	    			w[i]-=m;
	    			w[j]+=m;
	    			int a=w[0],b=w[1],c=w[2];
	    			if(!st[a][b][c]){
	    				n[++rear]={a,b,c};
	    				st[a][b][c]=true;
					}
				}
				
			}
		}
	}
}

int main(){
    scanf("%d%d%d",&A,&B,&C);
    bfs();
    for(int i=0;i<=C;++i){
    	for(int j=0;j<=B;++j){
    		if(st[0][j][i]){
    			printf("%d ",i);
    			break;
			}
		}
	}
		
	
	return 0;
} 