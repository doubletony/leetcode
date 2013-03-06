class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m, n;
        m = obstacleGrid.size();
        if (m == 0)
        {
            return 0;
        }

        n = obstacleGrid[0].size();
        if (n == 0)
        {
            return 0;
        }

        vector< vector<int> > grid( m, vector<int>(n, 0)  );

        bool blocked = false;
        for (int i = 0; i < n; i++)
        {
            if ( obstacleGrid[0][i] == 1)
            {
                blocked = true;
            }

            if ( blocked )
            {
                grid[0][i] = 0;
            }
            else
            {
                grid[0][i] = 1;
            }
        }

        blocked = false;
        for (int i = 0; i < m; i++)
        {
            if ( obstacleGrid[i][0] == 1)
            {
                blocked = true;
            }

            if ( blocked )
            {
                grid[i][0] = 0;
            }
            else
            {
                grid[i][0] = 1;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    grid[i][j] = 0;
                }
                else
                {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return grid[m-1][n-1];
    }
};