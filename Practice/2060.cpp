#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<climits>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 60;
int n, m;
char t[N][N],backup[N][N];
PII p[N * N];
int ind;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool st[N][N];
int res[N][N];
int ans=INT_MAX;
void remove(int i,int j){
    queue<PII> q;
    q.push(make_pair(i, j));
    t[i][j] = '.';
    st[i][j] = true;

        while (!q.empty())
        {
            PII tp = q.front();
        
            for (int k = 0; k < 4;++k){
                  int tx = tp.x + dx[k];
                  int ty = tp.y + dy[k];
                  if(tx<0||tx>=n||ty<0||ty>=m){
                     continue;
                  }
                  if(st[tx][ty]){
                   continue;
                  }
                  if(backup[tx][ty]=='.'){
                    p[ind].x = tx;
                    p[ind].y = ty;
                    ++ind;
                    st[tx][ty] = true;
                    //cout << tx << " " << ty << endl;
                  }
            }
            
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int tx = tp.x + dx[i];
                int ty = tp.y + dy[i];    

                if (tx < 0 || tx >= n || ty < 0 || ty >= m)
                {
                    continue;
                }
                if (st[tx][ty])
                {
                    continue;
                }
                if (backup[tx][ty] != 'X')
                {
                    continue;
                }
                t[tx][ty] = '.';
                st[tx][ty] = true;
                //cout << tx << " " << ty << endl;
                q.push(make_pair(tx, ty));
            }
        }
}
int bfs(int x,int y){
    memcpy(t, backup,sizeof backup);
    queue<PII> q;
    
    memset(res, -1, sizeof res);
    q.push(make_pair(x, y));

    res[x][y] = 1;

    while(!q.empty()){
        PII tp = q.front();
        q.pop();
        
        for (int i = 0; i < 4;++i){
            int tx = tp.x + dx[i];
            int ty = tp.y + dy[i];
            if(tx<0||tx>=n||ty<0||ty>=m){
                continue;
            }
            if(res[tx][ty]!=-1){
                continue;
            }
            if(t[tx][ty]=='X'){
                return res[tp.x][tp.y];
            }
            q.push(make_pair(tx, ty));
            res[tx][ty] = res[tp.x][tp.y] + 1;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n;++i){
        scanf("%s", t[i]);
    }
    memcpy(backup, t, sizeof t);
    bool flag = false;
    for (int i = 0; i < n;++i){
        for (int j = 0; j < m;++j){
            if(t[i][j]=='X'){
                remove(i,j);
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    memcpy(backup, t, sizeof t);
    
    // for (int i = 0; i < ind;++i){
    //     printf("%d %d\n", p[i].x, p[i].y);
    // }
    for (int i = 0; i < ind;++i){
        ans=min(bfs(p[i].x,p[i].y),ans);
    }

    printf("%d\n", ans);
    return 0;
}