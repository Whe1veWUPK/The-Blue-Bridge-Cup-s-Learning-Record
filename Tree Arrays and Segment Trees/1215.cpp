#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1000010;
int a[N], tr[N];
int sum[N];
int n;
long long res;
int lowbit(int x){
    return x & -x;
}
void add(int x,int v){
    for (int i = x; i <= N - 1;){
        tr[i] += v;
        i += lowbit(i);
    }
}
int query(int x){
    int res = 0;
    for (int i = x; i > 0;){
        res += tr[i];
        i -= lowbit(i);
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;++i){
        scanf("%d", &a[i]);
        ++a[i];
    }

    for (int i = 0; i < n;++i){
        sum[i] = query(N - 1) - query(a[i]);
        add(a[i], 1);
    }

    memset(tr, 0, sizeof tr);

    for (int i = n - 1; i >= 0;--i){
        sum[i] += query(a[i] - 1);
        add(a[i], 1);
    }

    for (int i = 0; i < n;++i){
        res +=(long long)sum[i] * (sum[i] + 1) / 2;
    }
    printf("%lld\n", res);
    return 0;
}