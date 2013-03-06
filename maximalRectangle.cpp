class Solution {


public:
    bool isExpandable(vector<vector<char> > &matrix, vector<vector<int> > &row, vector<vector<int> > &col, int curi, int curj, int di, int dj)
    {
        int r,c;
        r = row[curi-di][curj-dj];
        c = col[curi-di][curj-dj];

        if (r == 0 || c == 0)
        {
            return false;
        }

        if ( di != 0)
        {
            for (int i = 1; i <= r; i++)
            {
                if ( matrix[curi][curj-i] != '1' )
                {
                    return false;
                }
            }
        }


        if ( dj != 0)
        {
            for (int i = 1; i <= c; i++)
            {
                if ( matrix[curi-i][curj] != '1' )
                {
                    return false;
                }
            }
        }


        return true;
        
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT writea int main() function
        int n = matrix.size();
        if  (!n ) return 0;

        int m = matrix[0].size();
        
        if ( !m ) return 0;

        vector < vector <int> > row(n , vector<int>(m, 0) );
        vector < vector <int> > col(n , vector<int>(m, 0) );

        if ( matrix[0][0] == '1'  ) 
            row[0][0] = col[0][0] = 1;
        else
            row[0][0] = col[0][0] = 0;

        for (int i = 1; i < m; i++)
        {
            if ( matrix[0][i] == '1' )
            {
                row[0][i] = row[0][i-1] + 1;
                col[0][i] = 1;
            }
            else
            {
                row[0][i] = 0;
                col[0][i] = 0;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if ( matrix[i][0] == '1' )
            {
                row[i][0] = 1;
                col[i][0] = col[i-1][0];
            }
            else
            {
                row[i][0] = 0;
                col[i][0] = 0;
            }
        }

        for ( int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                // check for each '1'
                if ( matrix[i][j] == '0' )
                {
                    // simple case
                    row[i][j] = 0;
                    col[i][j] = 0;
                }
                else
                {
                    // check whether we can expand;
                    int curmax = 0;
                    row[i][j] = col[i][j] = 1;
                    if ( isExpandable(matrix, row, col, i, j, 1, 1) )
                    {
                        if ( curmax < (row[i-1][j-1] + 1) * (col[i-1][j-1]+1) )
                        {
                            curmax = (row[i-1][j-1] + 1) * (col[i-1][j-1]+1);
                            row[i][j] = row[i-1][j-1] + 1;
                            col[i][j] = col[i-1][j-1] + 1;
                        }
                    }

                    if ( isExpandable(matrix, row, col, i, j, 0, 1) )
                    {
                        if ( curmax < (row[i][j-1] + 1) * (col[i][j-1]+1) )
                        {
                            curmax = (row[i][j-1] + 1) * (col[i][j-1]+1);
                            row[i][j] = row[i][j-1];
                            col[i][j] = col[i][j-1] + 1;
                        }
                    }

                    if ( isExpandable(matrix, row, col, i, j, 1, 0) )
                    {
                        if ( curmax < (row[i-1][j] + 1) * (col[i-1][j]+1) )
                        {
                            curmax = (row[i-1][j] + 1) * (col[i-1][j]+1);
                            row[i][j] = row[i-1][j] + 1;
                            col[i][j] = col[i-1][j];
                        }
                    }
                }   
            }
        }
        int maxRec = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxRec = max( maxRec, row[i][j] * col[i][j] );
            }
        }
        return maxRec;
    }
};