#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 5010;
PII p[N];

int n;
int res1, res2;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;++i){
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    sort(p, p + n);
    int l2 = 0;
    int r2 = 0;
    int l1 = p[0].x;
    int r1 = p[0].y;
    res1 = max(r1 - l1, res1);
    res2 = max(r2 - l2, res2);
    for (int i = 1; i < n;++i){
        if(p[i].x<=r1){
            r1 = max(p[i].y,r1);
            res1 = max(res1, r1 - l1);
        }
        else if(p[i].x>r1){
            l2 = r1;
            r2 = p[i].x;
            res2 = max(res2, r2 - l2);
            l1 = p[i].x;
            r1 = p[i].y;
            res1 = max(res1, r1 - l1);
        }
    }
  
    printf("%d %d\n", res1, res2);
    return 0;
}