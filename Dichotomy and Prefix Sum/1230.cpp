#include<cstdio>
#include<iostream>

using namespace std;
const int N = 100001;
long long s[N],cnt[N];
long long ans;
int n, k;
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;++i){
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    cnt[0] = 1;
    for (int i = 1; i <= n;++i){
        ans += cnt[s[i] % k];
        ++cnt[s[i] % k];
    }
    printf("%lld\n", ans);
    return 0;
}