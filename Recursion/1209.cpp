#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n;
const int N = 25;

bool used[N], backup[N];
int ans;

bool check(int a,int c){
    long long b = n * (long long)c - a*c;
    if(!b||!a||!c){
        return false;
    }
    memcpy(backup, used, sizeof used);
    while(b){
        int t = b % 10;
        b /= 10;
        if(!t||backup[t]){
            return false;
        }
        backup[t] = true;
    }
    for (int i = 1; i <= 9;++i){
        if(!backup[i]){
            return false;
        }
    }
    return true;
}

void dfs_c(int u,int a,int c){
    if(u>=9){
        return;
    }
    if (check(a, c)){
            ++ans;
    }
    for (int i = 1; i <= 9;++i){
       if(!used[i]){
           used[i] = true;
           dfs_c(u + 1, a, c * 10 + i);
           used[i] = false;
       }
    }
}
void dfs_a(int u,int a){
    if(a>=n){
        return;
    }
    if(a){
        dfs_c(u, a, 0);
    }
    for (int i = 1; i <= 9;++i){
        if(!used[i]){
            used[i] = true;
            dfs_a(u + 1, a * 10 + i);
            used[i] = false;
        }
    }
}
int main(){
    cin >> n;
    dfs_a(0, 0);
    cout << ans << endl;

    return 0;
}