class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        DSU dsu(n);

        for (auto &it : edges) {

            int u = it[0];
            int v = it[1];

            // Agar dono pehle se connected hain,
            // to ye edge cycle bana rahi hai.
            if (dsu.findParent(u) == dsu.findParent(v))
                return {u, v};

            dsu.unionBySize(u, v);
        }

        return {};
    }
};