#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int N = 15;
int st[N];
void dfs(int u){
   if(u==n){
       for (int i = 0; i < n;++i){
          if(st[i]==1){
              printf("%d ", i + 1);
          }
          
       }
       printf("\n");
       return;
   }
   st[u] = 0;
   dfs(u + 1);
   st[u] = -1;

   st[u] = 1;
   dfs(u + 1);
   st[u] = -1;
}
int main(){
    cin >> n;
    dfs(0);
    return 0;
}