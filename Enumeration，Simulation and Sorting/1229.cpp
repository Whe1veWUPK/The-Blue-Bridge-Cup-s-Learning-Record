#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date{
    int year;
    int month;
    int day;
    bool operator<(const Date&d){
        if(year<d.year){
            return true;
        }
        else if((year==d.year)&&(month<d.month)){
            return true;
        }
        else if((year==d.year)&&(month==d.month)&&(day<d.day)){
            return true;
        }
        else{
            return false;
        }
    }
};

string input;
Date date[3];
bool checkMonth(int i){
    int month = (input[i] - '0') * 10 + input[i + 1] - '0';
    if(month>=1&&month<=12){
        return true;
    }
    else{
        return false;
    }
}
bool checkDay(int year,int month,int i){
    int day = (input[i] - '0') * 10 + input[i + 1] - '0';
    if(day==0){
        return false;
    }
    if(month!=2){
        if(day<=days[month]){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if((year%4==0&&year%100!=0)||(year%400==0)){
            if(day<=days[month]+1){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(day<=days[month]){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
int getMonth(int i){
    return (input[i] - '0') * 10 + input[i + 1] - '0';
}
int getDay(int i){
    return (input[i] - '0') * 10 + input[i + 1] - '0';
}
int main(){
    
    cin >> input;
    int cur = 0;
    bool isValid = true;
    //Y M D
    if(input[0]>='0'&&input[0]<='5'){
        date[cur].year = 20 * 100 + (input[0] - '0') * 10 + input[1] - '0';
    }
    else{
        date[cur].year = 19 * 100 + (input[0] - '0') * 10 + input[1] - '0';
    }
    if(checkMonth(3)){
        date[cur].month = getMonth(3);
        if(checkDay(date[cur].year,date[cur].month,6)){
            date[cur].day = getDay(6);
            ++cur;
        }
    }
    // M D Y
    if(input[6]>='0'&&input[6]<='5'){
        date[cur].year = 20 * 100 + (input[6] - '0') * 10 + input[7] - '0';
    }
    else{
        date[cur].year = 19 * 100 + (input[6] - '0') * 10 + input[7] - '0';
    }
    if(checkMonth(0)){
        date[cur].month = getMonth(0);
        if(checkDay(date[cur].year,date[cur].month,3)){
            date[cur].day = getDay(3);
            ++cur;
        }
    }
    // D M Y
    if(input[6]>='0'&&input[6]<='5'){
        date[cur].year = 20 * 100 + (input[6] - '0') * 10 + input[7] - '0';
    }
    else{
        date[cur].year = 19 * 100 + (input[6] - '0') * 10 + input[7] - '0';
    }
    if(checkMonth(3)){
        date[cur].month = getMonth(3);
        if(checkDay(date[cur].year,date[cur].month,0)){
            date[cur].day = getDay(0);
            ++cur;
        }
    }
    sort(date, date + cur);
    
    for (int i = 0; i < cur;++i){
        bool isDifferent = true;
        if(i!=0){
            for (int j = 0; j < i;++j){
                if(date[j].year==date[i].year&&date[j].month==date[i].month&&date[j].day==date[i].day){
                    isDifferent = false;
                    break;
                }
            }
        }
        if(isDifferent){
        cout << date[i].year << "-";
        if(date[i].month<10){
            cout << "0" << date[i].month<<"-";
        }
        else{
            cout << date[i].month<<"-";
        }
        if(date[i].day<10){
            cout << "0" << date[i].day;
        }
        else{
            cout << date[i].day;
        }
        cout << endl;
        }
    }
    return 0;
}