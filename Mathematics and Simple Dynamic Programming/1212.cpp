#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int N = 55, MOD = 1000000007;
int n, m, k;
int w[N][N];
int dp[N][N][13][14];


int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n;++i){
        for (int j = 1; j <= m;++j){
            scanf("%d", &w[i][j]);
            ++w[i][j];
        }
    }
    dp[1][1][1][w[1][1]] = 1;
    dp[1][1][0][0] = 1;
    for (int i = 1; i <= n;++i){
        for (int j = 1; j <= m;++j){
            if(i==1&&j==1){
                continue;
            }
            for (int u = 0; u <= k;++u){
                for (int v = 0; v <= 13; ++v){
                    int &value = dp[i][j][u][v];
                    value = (value + dp[i - 1][j][u][v]) % MOD;
                    value = (value + dp[i][j - 1][u][v]) % MOD;
                    if(u>0&&w[i][j]==v){
                        for (int q = 0; q < v;++q){
                            value = (value + dp[i - 1][j][u-1][q]) % MOD;
                            value = (value + dp[i][j - 1][u-1][q]) % MOD;
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= 13;++i){
        res = (res + dp[n][m][k][i]) % MOD;
    }
    printf("%d\n", res);
    return 0;
}
