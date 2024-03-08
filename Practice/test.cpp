#include<iostream>
#include<bitset>
using namespace std;

int main(){
    unsigned long t = -1;
    t /= 2;

    cout << bitset<32>(t) << endl;
    return 0;
}