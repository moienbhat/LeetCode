class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Reverse adjacency list
        vector<vector<int>> rev(V);
        vector<int> indegree(V, 0);

        for(int u = 0; u < V; u++) {
            for(int v : graph[u]) {
                rev[v].push_back(u);
                indegree[u]++;   // original outdegree becomes indegree in reverse
            }
        }

        queue<int> q;
        vector<int> safe;

        // Terminal nodes (outdegree = 0 in original graph → indegree = 0 in reverse)
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        // Kahn's algorithm on reversed graph
        while(!q.empty()) {
            int node = q.front(); q.pop();
            safe.push_back(node);

            for(int prev : rev[node]) {
                indegree[prev]--;
                if(indegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};