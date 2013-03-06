class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > nem;
        int n = matrix.size();
        nem.resize( n );
        for (int i = 0; i < n ; i++)
        {
            nem[i].resize(  n );
        }

        for ( int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nem[j][n-1-i] = matrix[i][j];
            }
        }

        matrix = nem;
    }
};