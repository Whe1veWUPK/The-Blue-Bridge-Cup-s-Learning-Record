#include <cstdio>
#include <iostream>
using namespace std;

const int N = 5002;

int s[N][N];
int n, r;
int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(s[x+1][y+1]==0){
           scanf("%hd", &s[x + 1][y + 1]);
        }
        else{
            short temp;
            scanf("%hd", &temp);
            s[x + 1][y + 1] += temp;
        }
    }
    for (int i = 1; i <= N-1;++i){
        for (int j = 1; j <= N-1;++j){
            s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
        }
    }
    if(r>=5001){
        printf("%d\n", s[N - 1][N - 1]);
    }
    else if(r==0){

        printf("%d\n", 0);
    }
    else {
        long long value = 0;
        for (int i = r; i < N;++i){
            for (int j = r; j < N;++j){
                long long temp = s[i][j] - s[i][j - r] - s[i - r][j] + s[i - r][j - r];
                value = max(value, temp);
            }
        }
        printf("%lld\n", value);
    }
    return 0;
}