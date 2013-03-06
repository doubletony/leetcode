class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > resl;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < i; j++)
            {
                if ( i == 0)
                {
                    break;
                }
                else
                {
                    tmp.push_back( resl[i-1][j-1] + resl[i-1][j] );
                }
            }
            if ( i != 0)
            {
                tmp.push_back(1);
            }
            resl.push_back(tmp);
        }
        return resl;
    }
};