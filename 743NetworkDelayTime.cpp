class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }

        // Initialize min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        // Initialize distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Process nodes
        while (!pq.empty()) {
            // Get the node with the smallest time
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Traverse all neighbors of the current node
            for (auto& [nbr, wt] : adj[node]) {
                // If shorter path is found to neighbor
                if (dist[nbr] > time + wt) {
                    // Update distance
                    dist[nbr] = time + wt;
                    // Push updated time to the priority queue
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        // Get maximum time
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};