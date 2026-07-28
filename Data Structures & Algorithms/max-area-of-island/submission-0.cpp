class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        for(int i = 0; i< r; i++){
            for(int j = 0; j< c; j++){
                int t = 0;
                if(grid[i][j] == 1){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    t++;
                    
                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();
                        if(temp.first < r-1 && grid[temp.first + 1][temp.second] == 1){
                            grid[temp.first + 1][temp.second] = 0;
                            q.push({temp.first + 1, temp.second });
                            t++;
                        }
                        if(temp.first > 0 && grid[temp.first - 1][temp.second] == 1){
                            grid[temp.first - 1][temp.second] = 0;
                            q.push({temp.first - 1, temp.second });
                            t++;
                        }
                        if(temp.second > 0 && grid[temp.first][temp.second - 1] == 1){
                            grid[temp.first][temp.second - 1] = 0;
                            q.push({temp.first, temp.second -1});
                            t++;
                        }
                        if(temp.second < c-1 && grid[temp.first ][temp.second + 1] == 1){
                            grid[temp.first][temp.second + 1] = 0;
                            q.push({temp.first, temp.second + 1});
                            t++;
                        }
                    }
                    ans = max(t, ans);
                }
            }
        }
        return ans;
        
    }
};
