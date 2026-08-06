class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int> ans;
    unordered_set<int> completed;

    bool dfs(unordered_set<int>& visiting, int course) {

        // Cycle detected
        if (visiting.count(course))
            return false;

        // Already processed
        if (completed.count(course))
            return true;

        visiting.insert(course);

        for (int pre : mp[course]) {
            if (!dfs(visiting, pre))
                return false;
        }

        visiting.erase(course);

        completed.insert(course);
        ans.push_back(course);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // Build graph
        for (auto &p : prerequisites) {
            mp[p[0]].push_back(p[1]);
        }

        unordered_set<int> visiting;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(visiting, i))
                return {};
        }

        return ans;
    }
};