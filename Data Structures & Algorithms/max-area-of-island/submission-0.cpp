class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c) {

        if (r < 0 ||
        r >= grid.size() ||
        c < 0 ||
        c >= grid[0].size() ||
        grid[r][c] == 0) {
        
        return 0;
        
}
    grid[r][c] = 0;

    int tracker = 1;

    tracker += dfs(grid, r - 1, c); // up
    tracker += dfs(grid, r + 1, c); // down
    tracker += dfs(grid, r, c - 1); // left
    tracker += dfs(grid, r, c + 1); // right
    
    return tracker;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int biggest_island = 0;

        for (int r = 0; r<grid.size(); r++ ) {
            for (int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1) {
                int num = dfs(grid, r,c);
                biggest_island = max(num, biggest_island);
                }

            
            }
        }
        if (biggest_island == 0) {
            return 0;
        }

        return biggest_island;


    }
};
