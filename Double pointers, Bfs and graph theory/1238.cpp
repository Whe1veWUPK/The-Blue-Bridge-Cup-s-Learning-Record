#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 100010;

int n, d, k;
PII logs[N];
int cnt[N];
bool st[N];
int main(){
    scanf("%d%d%d", &n, &d, &k);
    for (int i = 0; i < n;++i){
        scanf("%d%d", &logs[i].x, &logs[i].y);
    }
    sort(logs, logs + n);
    for (int i = 0, j = 0; i < n;++i){
        int id = logs[i].y;
        ++cnt[id];
        while(logs[i].x-logs[j].x>=d){
            cnt[logs[j].y]--;
            ++j;
        }
        if(cnt[id]>=k){
            st[id] = true;
        }
    }
    for (int i = 0; i < N;++i){
        if(st[i]){
            printf("%d\n", i);
        }
    }
    return 0;
}
