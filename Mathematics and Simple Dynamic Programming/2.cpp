#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000;
int v[N],w[N];
int n, m;
int dp[N];
bool used[N][N];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n;++i){
        scanf("%d%d", &v[i], &w[i]);
    }
    for (int i = 1; i <= m;++i){
        for (int j = 0; j < n;++j){
            if(v[j]<=i){
                if((dp[i]<dp[i-v[j]]+w[j])&&(!used[i-v[j]][j])){
                    dp[i] = dp[i - v[j]] + w[j];
                    memcpy(used[i], used[i - v[j]], sizeof used[i]);
                    used[i][j] = true;                    
                }
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}