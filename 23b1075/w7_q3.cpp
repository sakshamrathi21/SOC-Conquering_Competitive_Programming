#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

// Declare the DP array and the Trie data structure
vector<int> dp(5005);
vector<vector<int> > trie(1e6 + 5, vector<int>(26));
vector<bool> isEndOfWord(1e6 + 5);
int trieNodeCount = 0;

// Function to insert a word into the Trie
void insertWordInTrie(string& word)
{
    int currentNode = 0;
    for (char& ch : word) {
        if (!trie[currentNode][ch - 'a'])
            trie[currentNode][ch - 'a'] = ++trieNodeCount;
        currentNode = trie[currentNode][ch - 'a'];
    }
    isEndOfWord[currentNode] = true;
}

// Function to count the number of ways to form the string
// from index 'start'
int countWays(int start, string& S)
{
    int currentNode = 0, ways = 0;
    for (int i = start; i < S.size(); i++) {
        if (!trie[currentNode][S[i] - 'a'])
            return ways;
        currentNode = trie[currentNode][S[i] - 'a'];
        // If a word ends here, add the number of ways from the next index
        if (isEndOfWord[currentNode])
            ways = (ways + dp[i + 1]) % mod; 
    }
    return ways;
}

void solve(string& S, int K, string word[])
{
    for (int i = 0; i < K; i++) {
        // Insert each word into the Trie
        insertWordInTrie(word[i]); 
    }
    // Base case: One way to form an empty string
    dp[S.size()] = 1; 
    for (int i = S.size() - 1; i >= 0; i--) {
        // Fill the DP table from right to left
        dp[i] = countWays(i, S);
    }
    // The answer is the number of ways to form the string from index 0
    cout << dp[0]; 
}
// Driver Code
int main()
{
    // Input from user
    string S = "ababc";
    int K = 4;
    string arr[] = { "ab", "abab", "c", "cb" };
    solve(S, K, arr);
    return 0;
}
