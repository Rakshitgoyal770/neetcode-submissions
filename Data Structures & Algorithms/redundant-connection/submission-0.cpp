class Solution {
public:
    unordered_map<int, vector<int>> mp;

    bool dfs(int node, int parent, unordered_set<int>& visiting, vector<int>& path, unordered_set<int>& cycle) {
        visiting.insert(node);
        path.push_back(node);

        for (int next : mp[node]) {
            if (next == parent) {
                continue;
            }

            if (visiting.count(next)) {
                int i = path.size() - 1;

                while (path[i] != next) {
                    cycle.insert(path[i]);
                    i--;
                }

                cycle.insert(next);
                return true;
            }

            if (dfs(next, node, visiting, path, cycle)) {
                return true;
            }
        }

        path.pop_back();
        visiting.erase(node);

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        unordered_set<int> visiting;
        vector<int> path;
        unordered_set<int> cycle;

        dfs(1, -1, visiting, path, cycle);

        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (cycle.count(u) && cycle.count(v)) {
                return edges[i];
            }
        }

        return {};
    }
};