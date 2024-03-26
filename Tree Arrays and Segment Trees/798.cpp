#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int a[N][N], d[N][N];

int n, m, q;
void insert(int x1,int y1,int x2,int y2,int c){
    d[x1][y1] += c;
    d[x1][y2 + 1] -= c;
    d[x2 + 1][y1] -= c;
    d[x2 + 1][y2 + 1] += c;

}
int main(){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n;++i){
        for (int j = 1; j <= m;++j){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n;++i){
        for (int j = 1; j <= m;++j){
            insert(i, j, i, j, a[i][j]);
        }
    }
    int x1, y1, x2, y2, c;
    while(q--){
        scanf("%d%d%d%d%d", &x1,&y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n;++i){
        for (int j = 1; j <= m;++j){
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + d[i][j];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}