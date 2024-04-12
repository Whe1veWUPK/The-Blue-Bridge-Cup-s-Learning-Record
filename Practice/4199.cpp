#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>


using namespace std;
const int N=1350;
int a,b;
int n;
int cnt;
int d[N];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int init_divisors(){
    int x=gcd(a,b);
  
    for(int i=1;i<=x/i;++i){
        if(x%i==0){
        	d[cnt++]=i;
        	if(i!=x/i){
			d[cnt++]=x/i;
		    }
		} 
		
	}
}
int main(){
	scanf("%d%d",&a,&b);
	scanf("%d",&n);
	init_divisors();

	while(n--){
	    int L,R;
	    scanf("%d%d",&L,&R);
	    sort(d,d+cnt);
	    bool found=false;
	    for(int i=cnt-1;i>=0;--i){
	    	if(d[i]<=R&&d[i]>=L){
	    	   found=true;
	    	   printf("%d\n",d[i]);
	    	   break;
			}
		}
		if(!found){
			puts("-1");
		}
	}
	return 0;
} 