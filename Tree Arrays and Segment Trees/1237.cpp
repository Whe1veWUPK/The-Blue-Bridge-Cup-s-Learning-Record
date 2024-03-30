#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
LL x,  y;

int main(){
    scanf("%lld%lld", &x, &y);
    LL k = max(abs(x), abs(y));

    if(x>=y){
        
        printf("%lld", 4 * k * k + abs(k - x) + abs(k - y));
    }
    else{
        printf("%lld", 4 * k * k - abs(k - x) - abs(k - y));
    }

    return 0;
}