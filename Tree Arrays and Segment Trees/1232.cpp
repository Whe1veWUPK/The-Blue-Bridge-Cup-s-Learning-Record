#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
typedef long long LL;

const int N = 2000010;

int A, B, C, m;
LL a[N], d[N], bp[N];
int get(int i,int j,int k){
    return (i * B + j) * C + k;
}
int dir[8][4] = {
    {0, 0, 0, 1},
    {0, 0, 1, -1},
    {0, 1, 0, -1},
    {0, 1, 1, 1},
    {1, 0, 0, -1},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, -1},
}
;
int op[N/2][7];
bool check(int x){
    memcpy(d, bp, sizeof bp);
    int x1, x2, y1, y2, z1, z2, h;
    for (int i = 1; i <= x;++i){
        x1 = op[i][0];
        x2 = op[i][1];
        y1 = op[i][2];
        y2 = op[i][3];
        z1 = op[i][4];
        z2 = op[i][5];
        h = op[i][6];
        for (int t = 0; t < 8;++t){
            int x = dir[t][0] == 0 ? x1 : x2 + 1;
            int y = dir[t][1] == 0 ? y1 : y2 + 1;
            int z = dir[t][2] == 0 ? z1 : z2 + 1;
            d[get(x, y, z)] -= h * dir[t][3];
        }
    }
    memset(a, 0, sizeof a);
    for (int i = 1; i <= A;++i){
        for (int j = 1; j <= B;++j){
            for (int k = 1; k <= C;++k){
                a[get(i, j, k)] = d[get(i, j, k)];
                for (int t = 1; t < 8;++t){
                    int x = i - dir[t][0];
                    int y = j - dir[t][1];
                    int z = k - dir[t][2];
                    int p = dir[t][3];
                    a[get(i, j, k)] -= a[get(x, y, z)]*p;
                }
                if(a[get(i,j,k)]<0){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d%d%d", &A, &B, &C, &m);
    for (int i = 1; i <= A;++i){
        for (int j = 1; j <= B;++j){
            for (int k = 1; k <= C;++k){
                scanf("%lld", &a[get(i, j, k)]);
            }
        }
    }
    for (int i = 1; i <= m;++i){
        for (int j = 0; j < 7;++j){
            scanf("%d", &op[i][j]);
        }
    }
    for (int i = 1; i <= A;++i){
        for (int j = 1; j <= B;++j){
            for (int k = 1; k <= C;++k){
                for (int t = 0; t < 8;++t){
                    int x = i - dir[t][0];
                    int y = j - dir[t][1];
                    int z = k - dir[t][2];
                    int p = dir[t][3];
                    bp[get(i, j, k)] += a[get(x, y, z)] * p;
                }
            }
        }
    }

    int l = 1;
    int r = m;
    while(l<r){
        int mid = l + r >> 1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }

    printf("%d\n", r);
    return 0;
}