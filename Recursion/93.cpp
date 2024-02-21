#include<iostream>

using namespace std;
int n, m;
const int N = 25;
int state[N];
bool used[N];
void dfs(int u){
    if(u==m){
        for (int i = 0; i < m;++i){
            printf("%d ", state[i]);
        }
        puts("");
        return;
    }
    for (int i = 0; i < n;++i){
        if(!used[i]){
            if(u==0||(i+1>state[u-1])){
            used[i] = true;
            state[u] = i + 1;
            dfs(u + 1);
            used[i] = false;
            state[u] = 0;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    dfs(0);
    return 0;
}