#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100010;

int cnt[N];
int sum[N];
int n, l;

int main(){
    scanf("%d%d", &n, &l);

    for (int i = 0; i < n;++i){
        int t;
        scanf("%d", &t);
      
        ++cnt[t];
    }
    for (int i = 0; i < N;++i){
        if(i==0){
            sum[i] = cnt[i];
        }
        else{
            sum[i] = sum[i - 1] + cnt[i];
        }

    }
    
    int res = 0;
    for (int i = 0; i < N;++i){
        if(i==0){
            if(sum[N-1]+l>=i){
                res = max(res, i);
            }
        }
        else{
            if(sum[N-1]-sum[i-1]+min(l,cnt[i-1])>=i){
                res = max(res, i);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}