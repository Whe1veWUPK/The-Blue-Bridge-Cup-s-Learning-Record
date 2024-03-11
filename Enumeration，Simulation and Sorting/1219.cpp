#include<iostream>

using namespace std;

int w, m, n;

int main(){
    scanf("%d%d%d", &w, &m, &n);
    int **arr = new int*[max(m,n)/w+1];
    for (int i = 0; i < max(m, n) / w + 1;++i){
        arr[i] = new int[w + 1];
    }
    bool r = false;
    for (int i = 1; i <= max(m, n);++i){
        if(!r){
            if(i%w==0){
                r = !r;
                arr[(i - 1) / w][w] = i;
            }
            else{
                arr[(i - 1) / w][i % w] = i;
            }
        }
        else{
            if(i%w==0){
                r = !r;
                arr[(i - 1) / w][1] = i;
            }
            else{
                arr[(i - 1) / w][w + 1 - (i % w)] = i;
            }
        }
    }
    int res = abs((m - 1) / w - (n - 1) / w);
    int mx = (m - 1) / w;
    int nx = (n - 1) / w;
    int my = 0, ny = 0;
    for (int i = 1; i <= w;++i){
        if(arr[mx][i]==m){
            my = i;
        }
        if(arr[nx][i]==n){
            ny = i;
        }
    }
    res += abs(ny - my);
    printf("%d\n", res);
    return 0;
}