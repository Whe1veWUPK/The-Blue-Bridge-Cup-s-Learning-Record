#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 110;
int a[N];
int d[N];
int l[N];
int spend[N];
int n, t;
int get(int i){
    return max(0, a[i] - spend[i] * d[i]);
}
int cal(int n, int T){
    int res = 0;
    memset(spend, 0, sizeof spend);
    for (int i = 0; i < T;++i){
        int  t= 1;
        for (int j = t; j <= n;++j){
            if(get(t)<get(j)){
                t = j;
            }
        }
        res += get(t);
        ++spend[t];
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;++i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n;++i){
        scanf("%d", &d[i]);
    }
    for (int i = 2; i <= n;++i){
        scanf("%d", &l[i]);
        l[i] += l[i - 1];
    }

    scanf("%d", &t);
    int res = 0;
    for (int i = 1; i <= n;++i){
        res = max(res, cal(i, t - l[i]));
    }
    printf("%d\n", res);
    return 0;
}