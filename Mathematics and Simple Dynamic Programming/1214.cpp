#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int N = 1010,MOD=100000007;

int n, s, a, b;

int dp[N][N];
int getMod(int a,int b){
    return (a % b + b) % b;
}
int main(){
    int n, s, a, b;
    scanf("%d%d%d%d", &n, &s, &a, &b);
    dp[0][0] = 1;
    for (int i = 1; i < n;++i){
        for (int j = 0; j < n;++j){
            dp[i][j] = (dp[i - 1][getMod(j - a * i, n)] + dp[i - 1][getMod(j + b * i, n)])%MOD;
        }
    }
    printf("%d\n", dp[n - 1][getMod(s, n)]);
    return 0;
}
