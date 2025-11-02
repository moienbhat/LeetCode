#include<iostream>
#include<vector>
#include<string>

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if(k == 0 || s.empty()) return 0;

    unordered_map<char, int> freq;
    int left = 0;
    int maxLen = 0;

    for(int right=0; right<s.length(); right++) {
        freq[s[right]]++;

        while(freq.size() > k) {
            freq[s[left]]--;

            if(freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
                }
 maxLen = max(maxLen, right - left + 1);
}
return maxLen;
}

int main() {

    string s = "eceba";
    int k = 2;
    cout<< "The longest Substring with with at most K distinct characters present in it is : "<< lengthOfLongestSubstringKDistinct(s,k)<< endl;
    return 0;
}