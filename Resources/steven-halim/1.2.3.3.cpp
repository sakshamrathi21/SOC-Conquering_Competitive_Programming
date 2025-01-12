/**
 *    Author: Saksham Rathi
 *    Created: Thu Nov 28 12:18:50 IST 2024
**/


#include<iostream>
#include<cmath>
#include<ctime>
#include <iomanip>
#include<numbers>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<db> vdb;
#define MOD 1000000000


int main() {
    string month;
    int day, year;
    cin >> day >> month >> year;
    vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    // cout <<" hello " << day << " " << month << " " << year << endl;
    auto it = find(months.begin(), months.end(), month);
    int index = distance(months.begin(), it);
    // cout << " check " << index << endl;
    std::tm time_in = {0};
    time_in.tm_year = year - 1900; // Year since 1900
    time_in.tm_mon = index;   // Month since January (0-11)
    time_in.tm_mday = day;
    std::mktime(&time_in);
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::cout << "The day is: " << days[time_in.tm_wday] << std::endl;
}
