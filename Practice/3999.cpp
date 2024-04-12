#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long LL;
int t;
LL gcd(LL a, LL b){
    return b ? gcd(b, a % b) : a;
}
LL phi(LL x){
    LL res = x;
    for (int i = 2; i <= x / i;++i){
        if(x%i==0){
            while(x%i==0){
                x /= i;
            }
            res = res / i * (i - 1);
        }
        
    }
    if(x>1){
        res = res / x * (x - 1);
    }
    return res;
}
int main(){
    scanf("%d", &t);
    while(t--){
        LL a, m;
        scanf("%lld%lld", &a, &m);
        LL d = gcd(a, m);

  
        LL res = phi(m/d);
        printf("%lld\n", res);
    }
    return 0;
}