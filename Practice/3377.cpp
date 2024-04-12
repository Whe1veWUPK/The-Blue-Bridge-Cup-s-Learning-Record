#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=1010;
int cnt[N],num[N];
int n;

void init_divisors(int index,int x){
	for(int i=1;i<=x/i;++i){
		if(x%i==0){
			++cnt[index];
			if(i!=x/i){
				++cnt[index];
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
	   scanf("%d",&num[i]);
	}
	for(int i=0;i<n;++i){
		init_divisors(i,num[i]);
	}
	for(int i=0;i<n;++i){
		printf("%d\n",cnt[i]); 
	}
	
	return 0;
}