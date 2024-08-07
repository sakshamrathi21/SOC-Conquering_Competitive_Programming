#include<bits/stdc++.h>

using namespace std;

int editDistance(string str1 ,string str2){
    int** distance = new int*[str1.length() + 1];
    int n = str1.length();
    int m = str2.length();
    for(int i = 0; i <= n; i++){
        distance[i] = new int[m + 1];
    }

    for(int i = 0; i <= m; i++){
        distance[0][i] = i;
    }

    for(int i = 0; i <= n; i++){
        distance[i][0] = i;
    }
    int cost;
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1] ){
                cost = 0;
            } else {
                cost = 1;
            }
            
            distance[i][j] = min(distance[i-1][j]+1 , min(distance[i][j-1]+1,distance[i-1][j-1]+cost));
        }
    }

    return distance[n][m];
}
int main(){

    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << editDistance(str1,str2);

}