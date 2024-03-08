#include<cstring>
#include<iostream>
#include<cstdio>

using namespace std;
typedef long long LL;
const int N = 100010;

int p[N], t[N];
int d[N], b[N];
int n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;++i){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n;++i){
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n;++i){
        d[i] = p[i] - t[i];
    }

    for (int i = 1; i <= n + 1;++i){
        b[i] = d[i] - d[i - 1];
    }
    LL res = 0;
    for (int i = 1; i <= n + 1;++i){
        if(b[i]>0){
            res += b[i];
        }
    }
    printf("%lld\n", res);
    return 0;
}   