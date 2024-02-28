#include<cstdio>
#include<iostream>

using namespace std;
int n,res;
int main(){
    scanf("%d", &n);
    res = n;
    while(n>=3){
        res += n/3;
        n = n / 3 + n % 3;
    }
    printf("%d\n", res);
    return 0;
}