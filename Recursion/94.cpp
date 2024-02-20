#include <iostream>

using namespace std;
int n;
const int N = 9;
int state[N];
bool used[N];
void dfs(int u){
   if(u==n){
       for (int i = 0; i < n;++i){
           printf("%d ", state[i]);
       }
       puts("");
       return;
   }
   for (int i = 0; i < n;++i){
       if(!used[i]){
           used[i] = true;
           state[u] = i + 1;
           dfs(u + 1);
           used[i] = false;
           state[u] = 0;
       }
   }
}

int main(){
    scanf("%d", &n);
    dfs(0);
    return 0;
}