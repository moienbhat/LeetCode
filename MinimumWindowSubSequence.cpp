#include <bits/stdc++.h>
using namespace std;

string minWindowSubsequence(string S, string T) {
    int n = S.size(), m = T.size();
    int minLen = INT_MAX;
    string ans = "";

    int i = 0;
    while (i < n) {
        int j = 0;

        // Step 1: Move i until we find the first char of T
        while (i < n) {
            if (S[i] == T[j]) j++;
            if (j == m) break;  // matched full T
            i++;
        }

        if (i == n) break; // No more subsequences

        // Step 2: Backtrack to find start of window
        int end = i;
        j = m - 1;
        while (i >= 0) {
            if (S[i] == T[j]) j--;
            if (j < 0) break; // Found start of subsequence
            i--;
        }

        int start = i;
        if (end - start + 1 < minLen) {
            minLen = end - start + 1;
            ans = S.substr(start, minLen);
        }

        // Step 3: Move to next possible window
        i = start + 1;
    }

    return ans;
}

int main() {
    string S = "abcdebdde";
    string T = "bde";
    cout << minWindowSubsequence(S, T) << endl;  // Output: bcde
    return 0;
}
