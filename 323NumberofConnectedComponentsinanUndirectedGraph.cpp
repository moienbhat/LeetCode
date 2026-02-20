class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int components = 0;

        function<void(int)> dfs = [&](int node) {
            vis[node] = true;
            for (int nei : adj[node]) {
                if (!vis[nei]) dfs(nei);
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i);
            }
        }

        return components;
    }
};
