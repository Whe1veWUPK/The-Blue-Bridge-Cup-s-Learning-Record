#include<cstdio>
#include<iostream>

using namespace std;
const int N = 1010;
int a[N];
int dp[N];
int n;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;++i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n;++i){
        dp[i] = 1;
        for (int j = 0; j < i;++j){
            if(a[j]<a[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n;++i){
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
    return 0;
}