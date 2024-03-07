#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;

const int N = 10010;
int n;
int a[N];
int main(){
    int cnt;
    cin >> cnt;
    string line;
    getline(cin, line);
    while(cnt--){
        getline(cin, line);
        stringstream ssin(line);
        while(ssin>>a[n]){
            ++n;
        }

    }
    sort(a, a + n);
    int res1, res2;
    for (int i = 0; i < n;++i){
        if(a[i]==a[i-1]){
            res1 = a[i];
        }
        else if(a[i]>=a[i-1]+2){
            res2 = a[i] - 1;
        }

    }
    printf("%d %d\n", res2, res1);
    return 0;
}