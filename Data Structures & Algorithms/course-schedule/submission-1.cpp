class Solution {
public:
    unordered_map<int , vector<int>>mp;
    bool dfs(unordered_set<int>& visiting, int course){
        if(visiting.count(course)){
            return false;
        }
        if(mp[course].empty()){
            return true;
        }
        visiting.insert(course);
        for(auto pre: mp[course]){
            if(!dfs(visiting, pre)){
                return false;
            }
        }
        visiting.erase(course);
        mp[course].clear();

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < prerequisites.size(); i++ ){
            int temp = prerequisites[i][1];
            mp[prerequisites[i][0]].push_back(temp);
        } 

        unordered_set<int> visited;

        for(int i = 0; i < numCourses; i++){
            if(!dfs(visited, i)){
                return false;
            }
        }
        return true;
    }
};
