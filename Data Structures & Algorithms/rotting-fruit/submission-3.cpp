class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int temp = 0;
        int time = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    continue;
                }
                if(grid[i][j] == 1){
                    temp++;
                }
            }
        }
        if(temp == 0){
            return 0;
        }
        q.push({-1, -1}); 
        vector<pair<int, int>> dir = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while(!q.empty()){
            auto [ni, nj] = q.front();
            q.pop();
            if(ni == -1){
                if(q.empty()){
                    break;
                }
                time++;
                q.push({-1, -1});
                continue;
            }
            

            

            for(auto [di, dj] : dir){
                int i = di + ni;
                int j = dj + nj;

                if(i < 0 || j < 0 || i >= rows  || j >= cols){
                    continue;
                }
                if(grid[i][j] == 1){
                    grid[i][j] = 2;
                    temp --;
                    q.push({i, j});
                }


            }
        }
        return temp == 0 ? time : -1;
    }
    
};
