class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows == 1)
        {
            return s;
        }
        vector< vector< char> > a(nRows, vector< char > (0,' ') );
        int counter = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(counter < nRows)
            {
                a[counter].push_back( s[i] );
            }
            else
            {
                int rid = nRows - (counter+1 - nRows) - 1;
                a[rid].push_back( s[i] );
            }
            counter++;
            if ( counter == (nRows + nRows - 2))
            {
                counter = 0;
            }
        }
        string ret;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                ret.push_back(a[i][j] );
            }
        }
        return ret;
    }
};