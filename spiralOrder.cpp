class Solution {
public:

    void spir(vector<vector<int> > &matrix, int srow, int width, int height, vector<int> &vals)
    {
        if (width == 0 || height == 0)
        {
            return;
        }

        if (height == 1)
        {
            for (int i = srow; i < srow+width; i++)
            {
                vals.push_back( matrix[srow][i] );
            }
            return ;
        }

        if ( width == 1)
        {
            for (int i = srow; i < srow+height; i++)
            {
                vals.push_back( matrix[i][srow] );
            }
            return ;
        }

        for (int i = srow; i < srow+width; i++)
        {
            vals.push_back( matrix[srow][i] );
        }

        for(int i = srow+1; i < srow+height; i++)
        {
            vals.push_back( matrix[i][srow+width-1]  );
        }

        for(int i = srow+width-2; i >= srow; i--)
        {
            vals.push_back( matrix[srow+height - 1][i] );
        }

        for(int i = srow+height-2; i > srow; i--)
        {
            vals.push_back( matrix[i][srow]  );
        }
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m,n;
        vector<int> a;
        n = matrix.size();
        if ( n == 0)
        {
            return a;
        }
        m = matrix[0].size();
        int counter = 0;
        while( ( m > 0) && (n > 0) )
        {
            spir(matrix, counter, m, n, a);
            m -= 2;
            n -= 2;
            counter++;
        }
        return a;
    }
};