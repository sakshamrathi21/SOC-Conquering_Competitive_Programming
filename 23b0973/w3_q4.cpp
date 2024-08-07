#include <iostream>
#include <vector>
#include <string>
using namespace std;

int value(const string& x, const string& y) {
    int m = x.size();
    int n = y.size();

    vector<vector<int>> distance(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        distance[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        distance[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (x[i - 1] == y[j - 1])? 0 : 1;
            distance[i][j] = min(min( distance[i - 1][j] + 1,      
                                 distance[i][j - 1] + 1),      
                                 distance[i - 1][j - 1] + cost ); 
        }
    }

    return distance[m][n];
}
int main() {
    string str1, str2;
    cin >> str1 >> str2;

    cout << value(str1,str2) << endl;

    return 0;
}
                                                                                                    