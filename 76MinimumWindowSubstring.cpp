class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

    vector<int> hash(256, 0);
    for (char c : t)
        hash[c]++;

    int start = 0, count = 0, minLen = INT_MAX, sIndex = -1;
    int n = s.size(), m = t.size();

    for (int end = 0; end < n; end++) {
        hash[s[end]]--;

        if (hash[s[end]] >= 0) count++;


        while (count == m) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                sIndex = start;
            }

            hash[s[start]]++;
            if (hash[s[start]] > 0) count--;
            start++;
        }
    }

    if (sIndex == -1) return "";
    return s.substr(sIndex, minLen);
    }
};