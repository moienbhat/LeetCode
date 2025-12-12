#include <bits/stdc++.h>
using namespace std;

// ---------------------------------
// 1. DSU / Disjoint Set Class
// ---------------------------------
class DisjointSet {
public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

// ---------------------------------
// 2. Solution Class
// ---------------------------------
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        // Step 1: Union all existing 1s
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    int node = r * n + c;
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int adjNode = nr * n + nc;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        int maxIsland = 0;

        // Step 2: Try flipping each 0 to 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) continue;

                unordered_set<int> components;
                int islandSize = 1; // flipping this 0 → 1

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int parent = ds.findUPar(nr * n + nc);
                        if (!components.count(parent)) {
                            components.insert(parent);
                            islandSize += ds.size[parent];
                        }
                    }
                }

                maxIsland = max(maxIsland, islandSize);
            }
        }

        // Step 3: If grid already full of 1s
        for (int i = 0; i < n * n; i++) {
            maxIsland = max(maxIsland, ds.size[ds.findUPar(i)]);
        }

        return maxIsland;
    }
};
