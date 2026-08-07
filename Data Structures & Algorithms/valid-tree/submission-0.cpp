class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_set<int> visited;
    bool dfs(int node, int prev){
        if(visited.count(node)){
            return false;
        }
        visited.insert(node);

        for(auto adj : mp[node]){
            if(adj == prev){
                continue;
            }

            if(!dfs(adj, node)){
                return false;
            }
        }
        return true;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto node : edges){
            mp[node[1]].push_back(node[0]);
            mp[node[0]].push_back(node[1]);
        }
        if(dfs(0, -1) && visited.size() == n){
            return true;
        };
        return false;

    }
};
