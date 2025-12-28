class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if (!dict.count(endWord))
            return ans;

        unordered_map<string, vector<string>> parent;
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;

            while (sz--) {
                string word = q.front();
                q.pop();

                string original = word;

                for (int i = 0; i < word.size(); i++) {
                    char orig = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        if (!dict.count(word))
                            continue;

                        if (!visited.count(word)) {
                            parent[word].push_back(original);

                            if (word == endWord)
                                found = true;
                            else
                                levelVisited.insert(word);
                        }
                    }
                    word[i] = orig;
                }
            }

            for (auto &w : levelVisited) {
                visited.insert(w);
                q.push(w);
            }
        }

        if (!found)
            return ans;

        vector<string> path = {endWord};
        buildPaths(endWord, beginWord, parent, path, ans);

        for (auto &p : ans)
            reverse(p.begin(), p.end());

        return ans;
    }

    void buildPaths(string word, string beginWord,
                    unordered_map<string, vector<string>>& parent,
                    vector<string>& path,
                    vector<vector<string>>& ans) {
        if (word == beginWord) {
            ans.push_back(path);
            return;
        }

        for (string &p : parent[word]) {
            path.push_back(p);
            buildPaths(p, beginWord, parent, path, ans);
            path.pop_back();
        }
    }
};
