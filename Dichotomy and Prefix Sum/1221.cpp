#include<iostream>
#include<cstring>
#include <climits>
using namespace std;
const int N = 4;
long long ans[N],backup[N];
void printAns(){
    for (int i = 0; i < 4;++i){
        printf("%lld ", ans[i]);
    }
    puts("");
}
void printBackup(){
    for (int i = 0; i < 4;++i){
        printf("%lld ", backup[i]);
    }
    puts("");
}
long long findV(long long n,long long l, long long r){
    while(l<r){
        long long mid = l + r +  1 >> 1;
        if(mid*mid<=n){
            l = mid;
        }
        else{
            r = mid = 1;
        }
    }
    return l;
}
bool isSuccess(int n){
    if(ans[0]*ans[0]+ans[1]*ans[1]+ans[2]*ans[2]+ans[3]*ans[3]==n){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    long long n;

    scanf("%lld", &n);
    long long s = n;
    ans[N - 1] = findV(n, 0, n - 1);
    if(isSuccess(n)){
       printAns();
    }
    else{
        for (long long i = ans[N - 1] - 1; i >= 0; --i)
        {
            n = s;
            n -= i * i;
            ans[N - 2] = findV(n, 0, n - 1);
            if(isSuccess(s)){
                printAns();
            }
        }
    }
    return 0;
}