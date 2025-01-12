/**
 *    Author: Saksham Rathi
 *    Created: Sat Nov 30 20:14:25 IST 2024
**/


#include<iostream>
#include<cmath>
#include<ctime>
#include <iomanip>
#include<numbers>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<db> vdb;
#define MOD 1000000000


int main() {
    int T;
    cin >> T;
    for (int i = 0 ; i < T ; i ++) {
        string s1, s2;
        cin >> s1 >> s2;
        map<string, string> m1, m2;
        string key = "", value = "";
        for (int j = 1 ; j < s1.size() - 1 ; j ++ ) {
            if (s1[j] == ',') {
                m1[key] = value;
                key = "";
                value = "";
            }
            else if (s1[j] == ':') {
                key = value;
                value = "";
            }
            else {
                value += s1[j];
            }
        }
        m1[key] = value;
        key = "";
        value = "";
        for (int j = 1 ; j < s2.size() - 1 ; j ++ ) {
            if (s2[j] == ',') {
                m2[key] = value;
                key = "";
                value = "";
            }
            else if (s2[j] == ':') {
                key = value;
                value = "";
            }
            else {
                value += s2[j];
            }
        }
        m2[key] = value;
        vector<string> a, d, m;
        auto it1 = m1.begin(), it2 = m2.begin();
        while (it1 != m1.end() && it2 != m2.end()) {
            //  cout << " hello " << it1->first << " " << it2->first <<  endl;
            if (it1->first == it2->first) {
                if (it1 -> second != it2 -> second) {
                    m.push_back(it1 ->first);
                }
                it1++;
                it2++;
            }
            else if (it1->first < it2->first) {
                d.push_back(it1->first);
                it1++;
            }
            else {
                a.push_back(it2->first);
                it2++;
            }
        }
        while (it1 != m1.end()) {
            d.push_back(it1->first);
            it1++;
        }
        while (it2 != m2.end()) {
           
            a.push_back(it2->first);
            it2++;
        }
        if (a.size() + d.size() + m.size() == 0) {
            cout << "\nNo changes\n";
            continue;
        }
        
        if (a.size() != 0) cout << "\n+" << a[0];
        for (int i = 1 ; i < a.size() ; i ++ ) {
            cout << "," << a[i];
        }
        if (d.size() != 0) cout << "\n-" <<  d[0];
        for (int i = 1 ; i < d.size() ; i ++ ) {
            cout << "," << d[i];
        }
        if (m.size() != 0) cout << "\n*" << m[0];
        for (int i = 1 ; i < m.size() ; i ++ ) {
            cout << "," << m[i];
        }
        cout << "\n";
    }
}
