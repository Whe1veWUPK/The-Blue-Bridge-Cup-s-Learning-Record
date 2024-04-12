#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;
typedef long long LL;
const int N= 100010;
int t[N];
LL res[N];
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&t[i]);
	}
	int cur=1;
    int cnt=0;
    
    int round=1;
	for(int i=0;i<n;++i){
		res[round]+=t[i];
		++cnt;
		if(cnt==cur){
		    ++round;
			cur*=2;
			cnt=0;
		}
	}
	LL ans=res[1];
	int index=1;
    for(int i=1;i<=round;++i){
    	  if(cnt==cur&&i==round){
    	  	 break;
		  }
          if(res[i]>ans){
          	  index=i;
          	  ans=res[i];
		  }
	}


	
	printf("%d\n",index);
	return 0;
}