#!/bin/bash

file_name=$1

current_time=$(date)

touch "$file_name"

echo "/**
 *    Author: Saksham Rathi
 *    Created: $current_time
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }

    }
}" > "$file_name"

open "$file_name"
clear
