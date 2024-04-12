#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=210;
int m,s,c;
int b[N];
int zeros[N];
int main(){
   scanf("%d%d%d",&m,&s,&c);
   for(int i=0;i<c;++i){
   	   scanf("%d",&b[i]);
   }
   sort(b,b+c);
   int res=b[c-1]-b[0]+1;
   for(int i=1;i<c;++i){
   	   zeros[i]=b[i]-b[i-1]-1;
   }
   sort(zeros+1,zeros+c); 

   int ind=c-1;
   for(int i=0;i<m-1;++i){
   	   if(ind==0){
   	   	    break;
		  }
   	   res-=zeros[ind];
   	   --ind;
   }
   printf("%d\n",res);
   return 0;
}