#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int dx[5] = {0, -1,0,1, 0};
int dy[5] = {-1, 0, 0, 0, 1};

const int N = 6;
char g[N][N];
void turnOn(int x,int y){
    for (int i = 0; i < 5;++i){
        
            int a = dx[i] + x;
            int b = dy[i] + y;
            if(a<0||a>4||b<0||b>4){
                continue;
            }
            g[a][b] ^= 1;
        
    }
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int minstep =INT_MAX;
        for (int i = 0; i < 5;++i){
            for (int j = 0; j < 5;++j){
                cin >> g[i][j];
            }
        }
        char backup[N][N];
        memcpy(backup, g, sizeof g);
        for (int op = 0; op < 32;++op){
            memcpy(g, backup, sizeof backup);
            int step = 0;
            int temp = op;
            for (int i = 0; i < 5;++i){
                if(temp&1){
                    ++step;
                    turnOn(0, i);
                }
                temp=temp >> 1;
            }
            //cout << step << endl;
            for (int i = 0; i < 4; ++i){
                    for (int j = 0; j < 5; ++j){
                        if (g[i][j] == '0'){
                            ++step;
                            turnOn(i + 1, j);
                        }
                    }
            }
            bool success = true;
            for (int i = 0; i < 5;++i){
                if (g[4][i] == '0')
                {
                    success = false;
                }
            }
            //cout << step << endl;
            if(success){
                minstep = min(step, minstep);
            }
            
        }
        if(minstep>6){
            cout << -1 << endl;
        }
        else{
            cout << minstep << endl;
        }
    }
}