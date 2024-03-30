#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 100010, MOD = 99999997;
int a[N], b[N], c[N], p[N];
int n;

void discrete(int a[]){
    for (int i = 1; i <= n;++i){
        p[i] = i;
    }
    sort(p + 1, p + n + 1, [&](int x, int y)
         { return a[x] < a[y]; });
    for (int i = 1; i <= n;++i){
        a[p[i]] = i;
    }
}
int mergeSort(int l,int r){
    if(l>=r){
        return 0;
    }
    int mid = l + r >> 1;
    int res = (mergeSort(l, mid) % MOD + mergeSort(mid + 1, r) % MOD) % MOD;
    int i = l, j = mid + 1;
    int k = 0;
    while(i<=mid&&j<=r){
        if((b[i]<=b[j])){
            p[k++] = b[i++];
        }
        else{
            p[k++] = b[j++];
            res =(res+ (mid - i + 1)%MOD)%MOD;
        }
    }
    while(i<=mid){
        p[k++] = b[i++];
    }
    while(j<=r){
        p[k++] = b[j++];
    }
    for (int k = 0; k < r - l + 1;++k){
        b[k + l] = p[k];
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;++i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n;++i){
        scanf("%d", &b[i]);
    }
    discrete(a), discrete(b);
    for (int i = 1; i <= n;++i){
        c[a[i]] = i;
    }
    for (int i = 1; i <= n;++i){
        b[i] = c[b[i]];
    }
    LL res = mergeSort(1, n);
    printf("%lld\n", res);
    return 0;
} 