#include<cstdio>
#include<iostream>

using namespace std;
const int N = 60;
int n, m, k;
int a[N][N];
long long ans;
int main(){
    scanf("%d%d%d", &n, &m, &k);
    if (n + m - 1 < k)
    {
        printf("%d\n", 0);
        return 0;
    }
    for (int i = 1; i <= n;++i){
        for (int j = 1; j <= m;++j){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m + n - 1; ++i){
        
    }
    return 0;
}