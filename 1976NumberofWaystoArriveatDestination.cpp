class Solution {
public:
    const long long MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        // Step 1: Create adjacency list
        vector<vector<pair<int,long long>>> adj(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1], w = r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // Step 2: Dijkstra arrays
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        // Source initialization
        dist[0] = 0;
        ways[0] = 1;

        // Min-heap: {distance, node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, 0});

        // Step 3: Dijkstra's Algorithm
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue; // skip old values

            for (auto &edge : adj[node]) {
                int nbr = edge.first;
                long long wt = edge.second;

                long long newDist = d + wt;

                // Case 1: Found a shorter path
                if (newDist < dist[nbr]) {
                    dist[nbr] = newDist;
                    ways[nbr] = ways[node];   // carry over count
                    pq.push({newDist, nbr});
                }
                // Case 2: Found another path with SAME shortest distance
                else if (newDist == dist[nbr]) {
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
