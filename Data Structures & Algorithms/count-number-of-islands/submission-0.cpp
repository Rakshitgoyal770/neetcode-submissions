class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        int count = 0;

        for(int i = 0; i < r; i++) {

            for(int j = 0; j < c; j++) {

                if(grid[i][j] == '1') {

                    count++;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';

                    while(!q.empty()) {

                        auto temp = q.front();
                        q.pop();

                        int x = temp.first;
                        int y = temp.second;

                        // Right
                        if(y + 1 < c && grid[x][y+1] == '1') {
                            grid[x][y+1] = '0';
                            q.push({x,y+1});
                        }

                        // Left
                        if(y - 1 >= 0 && grid[x][y-1] == '1') {
                            grid[x][y-1] = '0';
                            q.push({x,y-1});
                        }

                        // Down
                        if(x + 1 < r && grid[x+1][y] == '1') {
                            grid[x+1][y] = '0';
                            q.push({x+1,y});
                        }

                        // Up
                        if(x - 1 >= 0 && grid[x-1][y] == '1') {
                            grid[x-1][y] = '0';
                            q.push({x-1,y});
                        }
                    }
                }
            }
        }

        return count;
    }
};
