#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N], d[N];

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;++i){
        scanf("%d", &a[i]);
        d[i] = a[i] - a[i - 1];
    }

    int l, r, c;
    while(m--){
        scanf("%d%d%d", &l, &r, &c);
        d[l] += c;
        d[r + 1] -= c;
    }
    for (int i = 1; i <= n;++i){
        d[i] += d[i - 1];
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}