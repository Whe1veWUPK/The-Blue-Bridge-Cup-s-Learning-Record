#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<cmath>

using namespace std;

const int N = 5;
char s[N][N],backup[N][N];
void turnOn(int x,int y){
    for (int i = 0; i < 4;++i){
        s[x][i] ^= 6;
        s[i][y] ^= 6;
    }
    s[x][y] ^= 6;
}

int main(){
    int minStep =INT_MAX;
    vector<pair<int, int>> ans;
    for (int i = 0; i < 4;++i){
        for (int j = 0; j < 4;++j){
            cin >> s[i][j];
        }
    }
    memcpy(backup, s, sizeof s);
    for (int op = 0; op <pow(2,16) ; ++op){
        memcpy(s, backup, sizeof backup);
        int step = 0;
        vector<pair<int, int>> tempAns;
        int temp = op;
        for (int i = 0; i < 4;++i){
            for (int j = 0; j < 4;++j){
                if(temp&1){
                    ++step;
                    tempAns.push_back({i + 1, j + 1});
                    turnOn(i, j);
                }
                temp = temp >> 1;
            }
        }
        bool success = true;
        for (int i = 0; i < 4;++i){
            for (int j = 0; j < 4;++j){
                if(s[i][j]=='+'){
                    success = false;
                    break;
                }
            }
            if(!success){
                break;
            }
        }
        if(!success){
            continue;
        }
        else{
            if(minStep>step){
                ans = tempAns;
                minStep = step;
            }
        }
    }
    cout << minStep << endl;
    for (int i = 0; i < ans.size();++i){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}