class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
          vector<pair<int, int>> adj[n];
        int mod = 1e9 + 7;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        // {dist,src}
        pq.push({0, 0});
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        while (!pq.empty()) {
            auto node = pq.top().second;
            auto d = pq.top().first;
            pq.pop();
            if(node== n-1) return ways[n-1];
            for (auto it : adj[node]) {
                long long edwt = it.second;
                long long neighbour = it.first;
                if (edwt + d < dist[neighbour]) {
                    dist[neighbour] = edwt + d;
                    pq.push({dist[neighbour],neighbour});
                    ways[neighbour]=ways[node];
                } else if (edwt + d == dist[neighbour]) {
                    ways[neighbour] =
                        (ways[neighbour] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]; 
    }
};