class Solution {
public:

    // dp, O(n^2) space
    int mimtri(vector<vector<int> > &triangle, vector<vector<int> > &table, int row, int col)
    {
        if ( row >= triangle.size())
        {
            return 0;
        }

        if ( col >= triangle[row].size() )
        {
            return 0;
        }

        if ( table[row][col] == -1)
        {
            table[row][col]  = triangle[row][col] + min( mimtri(triangle, table, row+1, col), mimtri(triangle, table, row+1, col+1) );
        }
        return table[row][col];
    }

    // dp, O(n) space
    int mimtri2(vector<vector<int> > &triangle)
    {
        int row = triangle.size();
        if (row <= 0)
        {
            return 0;
        }
        vector<int> tmp = triangle[row-1];

        for ( int i = row - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                tmp[j] = min( tmp[j], tmp[j+1] ) + triangle[i][j];
            }
        }
        return tmp[0];
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // method 1
        //vector<vector<int> > table = triangle;
        //for (int i = 0; i < table.size(); i++)
        //{
        //    for (int j = 0; j < table[i].size(); j++)
        //    {
        //        table[i][j] = -1;
        //    }
        //}
        //return mimtri(triangle, table, 0, 0);

        //method 2
        return mimtri2(triangle);
    }
};