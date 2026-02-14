#include<iostream>
#include<vector>


using namespace std;

// Class to represent the solution
class Solution {
private:
    // Function to perform Topological Sort using Kahn's Algorithm (BFS)
    vector<int> topoSort(int V, vector<int> adj[]) {
        // indegree[i] will store number of incoming edges for node i
        vector<int> indegree(V, 0);

        // Compute indegree of all vertices
        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Queue to store all vertices with indegree = 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo; // to store the topological order

        // Process until queue is empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Add this node to result
            topo.push_back(node);

            // For each neighbor, decrease its indegree
            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                // If indegree becomes 0, push it into the queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topo;
    }

public:
    // Function to find the order of characters in the alien dictionary
    string findOrder(string dict[], int N, int K) {
        // Graph represented as adjacency list
        vector<int> adj[K];

        // Build graph by comparing adjacent words in dictionary
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            // Find the first different character and create edge
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break; // only the first mismatch matters
                }
            }
        }

        // Perform topological sort on the graph
        vector<int> topo = topoSort(K, adj);

        // Convert numeric values back to characters
        string ans = "";
        for (auto node : topo) {
            ans += char(node + 'a');
        }

        return ans;
    }
};

// Driver Code
int main() {
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    Solution obj;
    string ans = obj.findOrder(dict, N, K);

    // Print result
    for (auto ch : ans) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}