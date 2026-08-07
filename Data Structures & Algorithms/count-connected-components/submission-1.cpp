class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_set<int> visited;
    int count = 0;

    void dfs(int i, int prev){
        if(visited.count(i)){
            return;
        }

        visited.insert(i);


        for(auto adj : mp[i]){
            if(adj == prev){
                continue;
            }
            dfs(adj, i);
        }

        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        for(auto ed : edges){
            mp[ed[0]].push_back(ed[1]);
            mp[ed[1]].push_back(ed[0]);
        }

        for(int i = 0; i < n; i++){
            if(visited.count(i)){
                continue;
            }
            else{
                count++;
                dfs(i, -1);
            }
        }

        return count;

    }
};
