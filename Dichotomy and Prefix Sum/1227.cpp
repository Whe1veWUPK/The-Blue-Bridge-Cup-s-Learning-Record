#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<pair<long long,long long>> chololate;
int N, K;
bool isSuccess(int mid,int K,int N){
    int cur = 0;
    for (int i = 0; i < N;++i){
        cur += ((chololate[i].first / mid) * (chololate[i].second / mid));
    }
    if(cur<K){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N;++i){
        pair<int, int> cho;
        scanf("%d %d", &cho.first, &cho.second);

        chololate.push_back(cho);
    }
    int l = 1;
    int r = 1e5;
    while(l<r){
        int mid = l + r +  1 >> 1;
        if(isSuccess(mid,K,N)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    printf("%d", l);
    return 0;
}