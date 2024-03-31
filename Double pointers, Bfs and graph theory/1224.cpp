#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 10010;
int n;
int b[N];
bool st[N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;++i){
        scanf("%d", &b[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n;++i){
        if(!st[i]){
            ++cnt;
            for (int j = i; !st[j];j=b[j]){
                st[j] = true;
            }
        }
    }
    printf("%d\n", n - cnt);
    return 0;
}