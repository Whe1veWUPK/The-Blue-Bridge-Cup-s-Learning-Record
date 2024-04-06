#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10;
char d1[N];
char d2[N];
int days[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date{
    int year;
    int month;
    int day;
    bool operator<(Date const& d){
        if(year<d.year){
            return true;
        }
        else if(year==d.year&&month<d.month){
            return true;
        }
        else if(year==d.year&&month==d.month&&day<d.day){
            return true;
        }
        return false;
    }
};
Date date1;
Date date2;
void transform(){
    date1.day = d1[7] - '0' + 10 * (d1[6] - '0');
    date2.day = d2[7] - '0' + 10 * (d2[6] - '0');
    date1.month = d1[5] - '0' + 10 * (d1[4] - '0');
    date2.month = d2[5] - '0' + 10 * (d2[4] - '0');
    int y1=0, y2=0;
    for (int i = 0; i <= 3; ++i){
        y1 = y1 * 10 + (d1[i] - '0');
        y2 = y2 * 10 + (d2[i] - '0');
    }
    date1.year = y1;
    date2.year = y2;
}
bool isLeapYear(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
int calLeapNum(int s,int e){
    int res = 0;
    for (int i = s + 1; i < e;++i){
        if(isLeapYear(i)){
            ++res;
        }
    }
    return res;
}
int calDay(Date d){
    int res = 0;
    if(isLeapYear(d.year)){
        for (int i = 1; i < d.month;++i){
            if(i!=2){
                res += days[i];
            }
            else{
                res += 29;
            }
        }
    }
    else{
        for (int i = 1; i < d.month;++i){
            res += days[i];
        }
    }
    res += d.day;
    return res;
}
int calDiff(){

    int bigger = 0;
    if(date1<date2){
        bigger = 2;
    }
    else{
        bigger = 1;
    }
    
    int dy = 0;
    int res = 0;
    
    if(bigger==1){
        dy = date1.year - date2.year;
        int leapNum = calLeapNum(date2.year, date1.year);
        res =res+ 366 * leapNum + max(0,(dy-1 - leapNum)) * 365;
        res =res+calDay(date1);
        if(dy!=0){
        if(isLeapYear(date2.year)){
            res =res+ 366 - calDay(date2)+1;
        }
        else{
            res =res+ 365 - calDay(date2)+1;
        }
        }
        else{
            res = (calDay(date1) - calDay(date2) + 1);
        }
    }
    else{
        dy = date2.year - date1.year;

        int leapNum = calLeapNum(date1.year, date2.year);
        res =res+ 366 * leapNum + max(0,(dy -1- leapNum)) * 365;

        res += calDay(date2);
        if(dy!=0){
         if(isLeapYear(date1.year)){
            res =res+ 366 - calDay(date1)+1;
         }
         else{
            res =res+ 365 - calDay(date1) +1;
         }
        }
        else{
            
            res = (calDay(date2) - calDay(date1) + 1);
        }
    }
    
    return res;
}
int main(){

    while(cin>>d1){
        cin >> d2;
        transform();

        int res = calDiff();
        printf("%d\n", res);
    }

    return 0;
}
