class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        const int INF = INT_MAX / 2;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Distance to itself = 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // Load edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Find city with smallest reachable count
        int answerCity = -1;
        int smallest = INT_MAX;

        for (int city = 0; city < n; city++) {
            int count = 0;
            for (int other = 0; other < n; other++) {
                if (dist[city][other] <= distanceThreshold)
                    count++;
            }

            // tie-breaking: choose LARGER index
            if (count <= smallest) {
                smallest = count;
                answerCity = city;
            }
        }

        return answerCity;
    }
};
