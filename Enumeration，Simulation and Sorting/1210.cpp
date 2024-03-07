#include<iostream>


using namespace std;

const int N = 10010, INF=1e8;
int n;
int a[N];

int main(){
   scanf("%d",&n);
   for(int i=0;i<n;++i){
           scanf("%d",&a[i]);
   }
   int res=0;
   for(int i=0;i<n;++i){
           int minv=INF,maxv=-INF;
           for(int j=i;j<n;++j){
                   maxv = max(maxv,a[j]);
                   minv = min(minv, a[j]);
                   if(maxv-minv==j-i){
                        ++res;
                   }
           }
   }
   printf("%d\n",res);
   return 0;   
               
}
