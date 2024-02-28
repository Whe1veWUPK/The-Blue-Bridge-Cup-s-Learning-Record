#include<cstdio>
#include<iostream>

using namespace std;
const int N = 51;
int a[N];
int n,lr,rl;
int main(){
    cin >> n;
    for (int i = 0; i < n;++i){
        cin >> a[i];
    }
    for (int i = 1; i < n;++i){
        if (abs(a[0]) > abs(a[i]) && a[i]>0){
            ++lr;
        }
        if(abs(a[0])<abs(a[i])&&a[i]<0){
            ++rl;
        }
    }
    if((a[0]<0&&lr==0)||(a[0]>0&&rl==0)){
        cout << 1 << endl;
    }
    else{
        cout << lr + rl + 1 << endl;
    }
    return 0;
}