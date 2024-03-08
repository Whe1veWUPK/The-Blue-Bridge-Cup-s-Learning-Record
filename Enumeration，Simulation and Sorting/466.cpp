#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isValid(int date){
    int year = date /10000 ;
    int month = (date /100 ) % 100;
    int day = date % 100;
    
    if(month>12||month==0||day==0){
        return false;
    }
    if(month!=2&&days[month]<day){
        return false;
    }
    if(month==2){
        if((year%4==0&&year%100!=0)||(year%400==0)){
            if(day>days[month]+1){
                return false;
            }
        }
        else{
            if(day>days[month]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int date1;
    int date2;
    scanf("%d", &date1);
    scanf("%d", &date2);
    int res = 0;
    for (int i = 1000; i <= 9999;++i){
        int date = i;
        int x = i;
        for (int j = 0; j < 4;++j){
            int v = x % 10;
            date=date * 10 + v;
            x /= 10;
        }
        if(isValid(date)&&(date1<=date)&&(date<=date2)){
            ++res;
        }
    }
    printf("%d\n", res);
    return 0;
}