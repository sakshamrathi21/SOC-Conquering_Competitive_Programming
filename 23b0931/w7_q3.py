MOD = 10**9 + 7

# Declare the DP array and the Trie data structure
dp = [0] * 5005
trie = [[0] * 26 for _ in range(10**6 + 5)]
isEndOfWord = [False] * (10**6 + 5)
trieNodeCount = 0

# Function to insert a word into the Trie
def insertWordInTrie(word):
    global trieNodeCount
    currentNode = 0
    for ch in word:
        index = ord(ch) - ord('a')
        if not trie[currentNode][index]:
            trieNodeCount += 1
            trie[currentNode][index] = trieNodeCount
        currentNode = trie[currentNode][index]
    isEndOfWord[currentNode] = True

# Function to count the number of ways to form the string
# from index 'start'
def countWays(start, S):
    currentNode = 0
    ways = 0
    for i in range(start, len(S)):
        index = ord(S[i]) - ord('a')
        if not trie[currentNode][index]:
            return ways
        currentNode = trie[currentNode][index]
        # If a word ends here, add the number of ways from the next index
        if isEndOfWord[currentNode]:
            ways = (ways + dp[i + 1]) % MOD
    return ways

def solve(S, K, word):
    for w in word:
        # Insert each word into the Trie
        insertWordInTrie(w)
    # Base case: One way to form an empty string
    dp[len(S)] = 1
    for i in range(len(S) - 1, -1, -1):
        # Fill the DP table from right to left
        dp[i] = countWays(i, S)
    # The answer is the number of ways to form the string from index 0
    print(dp[0])

# Driver Code
if __name__ == "__main__":
    # Input from user
    S = "ababc"
    K = 4
    arr = ["ab", "abab", "c", "cb"]
    solve(S, K, arr)