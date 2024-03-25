#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 32010;
int n;
int tr[N],level[N];
int lowbit(int x){
    return x & -x;
}
void add(int a){
    for (int i = a; i <= N;){
        tr[i]++;
        i += lowbit(i);
    }
}
int sum(int x){
    int res = 0;
    for (int i = x; i > 0;i-=lowbit(i)){
        res += tr[i];
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;++i){
        int x, y;
        scanf("%d%d", &x, &y);
        ++x;
        ++level[sum(x)];
        add(x);
    }
    for (int i = 0; i < n;++i){
        printf("%d\n", level[i]);
    }
    return 0;
}