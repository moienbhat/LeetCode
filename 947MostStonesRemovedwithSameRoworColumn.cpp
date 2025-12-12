class DSU {
public:
    unordered_map<int, int> parent;


    int find(int x) {

        if (parent.find(x) == parent.end())
            parent[x] = x;


        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }


    void unite(int x, int y) {

        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;


        for (auto& stone : stones) {
            dsu.unite(stone[0], stone[1] + 10001);
        }

        unordered_set<int> components;


        for (auto& stone : stones) {
            components.insert(dsu.find(stone[0]));
        }


        return stones.size() - components.size();
    }
};
