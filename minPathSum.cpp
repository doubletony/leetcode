// typical DP



class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > dis;
        int n, m;
        n = grid.size();
        if (n > 0)
        {
            m = grid[0].size();
            if ( m == 0)
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }

        for (int i = 0; i < n ; i++)
        {
            vector<int> newOne(m, -1);
            dis.push_back(newOne);
        }

        dis[0][0] = grid[0][0];

        for (int i = 1; i < m; i++ )
        {
            dis[0][i] = dis[0][i-1] + grid[0][i];
        }

        for (int i = 1; i < n ; i++)
        {
            dis[i][0] = dis[i-1][0] + grid[i][0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dis[i][j] = min( dis[i-1][j] + grid[i][j], dis[i][j-1] + grid[i][j] );
            }
        }
        
        return dis[n-1][m-1];
    }
};