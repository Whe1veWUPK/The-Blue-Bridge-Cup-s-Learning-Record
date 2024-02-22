#include <iostream>
#include <cstring>

using namespace std;

string input;
string target;
void turnOver(int i){
    input[i] ^= 69;
    input[i + 1] ^= 69;
}
int main(){
    cin >> input;
    cin >> target;
    
    int times = 0;
    for (int i = 0; i < input.size()-1;++i){
        if(input[i]!=target[i]){
            ++times;
            turnOver(i);
        }
    }
    cout << times << endl;
    return 0;
}