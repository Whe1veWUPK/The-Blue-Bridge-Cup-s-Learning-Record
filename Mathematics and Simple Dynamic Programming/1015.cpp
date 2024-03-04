#include <cstdio>
#include <iostream>

using namespace std;

int n;
void solve(){
    int r, c;
    int res = 0;
    scanf("%d%d", &r, &c);
    int **arr = new int *[r+1];
    for (int i = 0; i <= r;++i){
        arr[i] = new int[c+1];
    }
    for (int i = 1; i <= r;++i){
        for (int j = 1; j <= c;++j){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= r;++i){
        for (int j = 1; j <= c;++j){
            arr[i][j] = max(arr[i - 1][j] + arr[i][j], arr[i][j - 1] + arr[i][j]);
        }
    }
    printf("%d\n", arr[r][c]);
}
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        solve();
    }
}