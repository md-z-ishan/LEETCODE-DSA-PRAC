class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             int &nodes,
             int &edges)
    {
        vis[node] = 1;
        nodes++;

        edges += adj[node].size();

        for (int neighbour : adj[node]) {

            if (vis[neighbour] == 0) {
                dfs(neighbour, adj, vis, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
         for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int complete = 0;

        for (int i = 0; i < n; i++) {

            if (vis[i] == 0) {

                int nodes = 0;
                int edgeCount = 0;

                dfs(i, adj, vis, nodes, edgeCount);

                edgeCount = edgeCount / 2;

                int requiredEdges = (nodes * (nodes - 1)) / 2;

                if (edgeCount == requiredEdges) {
                    complete++;
                }
            }
        }

        return complete;
    }
};