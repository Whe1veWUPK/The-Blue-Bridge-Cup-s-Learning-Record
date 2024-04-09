#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
 
using namespace std;


const int N=70;

int n;
int sticks[N];
int sum,len;
bool st[N];
bool dfs(int u,int cur,int start ){
	if(u*len==sum){
		return true;
	}
	if(cur==len){
		return dfs(u+1,0,0);
	}
	for(int i=0;i<n;++i){
		if(st[i]){
			continue;
		}
		if(cur+sticks[i]<=len){
			st[i]=true;
			if(dfs(u,cur+sticks[i],start+1)){
				return true;
			}
			st[i]=false;
		}
		if(!cur||cur+sticks[i]==len){
			return false;
		}
		int j=i+1;
		while(j<n&&sticks[j]==sticks[i]){
			
			++j;
		}
		i=j-1;
	}
	return false;
}

int main() {
	while(cin>>n,n){
		sum=len=0;
        for(int i=0;i<n;++i){
        	scanf("%d",&sticks[i]);
        	sum+=sticks[i];
        	len=max(len,sticks[i]);
		}
		sort(sticks,sticks+n,greater<int>());
		memset(st,0,sizeof st);
		while(true){
			if(sum%len==0&&dfs(0,0,0)){
				printf("%d\n",len);
				break;
			}
		    ++len;
		}
		
	}  

	return 0;
} 