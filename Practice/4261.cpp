#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef long long LL;

const int N = 500010;

char m[N];
int l[N], r[N];
LL res;
int n;
int main(){
    scanf("%d", &n);
    scanf("%s", m);
    for (int i = 0,lg=0,lh=0; i < n;++i){
        if(m[i]=='G'){
            ++lg;
            l[i] = lh;
            lh = 0;
        }
        else{
            ++lh;
            l[i] = lg;
            lg = 0;
        }
    }
    for (int i = n - 1, rg = 0, rh = 0; i >= 0;--i){
        if(m[i]=='G'){
            ++rg;
            r[i] = rh;
            rh = 0;
        }
        else{
            ++rh;
            r[i] = rg;
            rg = 0;
        }
    }
    for (int i = 0; i < n;++i){
        res += (LL)l[i] * r[i] + max(0, r[i] - 1) + max(0, l[i] - 1);
    }
    printf("%lld", res);
    return 0;
}
