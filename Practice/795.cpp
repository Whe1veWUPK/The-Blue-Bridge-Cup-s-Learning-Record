#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100010;
int s[N], a[N];
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;++i){
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    int l, r;
    while(m--){
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);

    }
    return 0;
}
