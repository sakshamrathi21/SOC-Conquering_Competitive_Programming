#!/bin/bash

file_name=$1

current_time=$(date)

touch "$file_name"
echo "/**
 *    Author: Saksham Rathi
 *    Created: $current_time
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
    
}" > "$file_name"

open "$file_name"
