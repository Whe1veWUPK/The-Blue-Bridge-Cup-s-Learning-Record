#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 100000;
int n;
int res;
typedef struct Fraction{
    int s;
    int m;
    bool operator<(Fraction const& f){
        double fa = (double)f.s / (double)f.m;
        double a = (double)s / (double)m;
        if(a<fa){
            return true;
        }
        else{
            return false;
        }
    }
};
Fraction f[N];
bool rPrime(int x,int y){
    int mi = min(x, y);
    int ma = max(x, y);

    for (int i=ma;i<=x*y;i+=ma){
        if(i%mi==0&&i!=x*y){
            return false;
        }
        
    }
    return true;
}
int main(){
    scanf("%d", &n);
    printf("%d/%d\n", 0, 1);
    int index = 0;
    for (int i = 2; i <= n;++i){
        for (int j = 1; j <i;++j){
            if(rPrime(j,i)){
                f[index].s = j;
                f[index].m = i;
                ++index;
            }
            else{
                continue;
            }
        }
    }
    sort(f, f + index);
    for (int i = 0; i < index;++i){
        printf("%d/%d\n", f[i].s, f[i].m);
    }
    printf("%d/%d\n", 1, 1);
    return 0;
}