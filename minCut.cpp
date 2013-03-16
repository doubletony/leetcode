class Solution {
public:

    typedef std::unordered_map<string, int> hashMap;
    typedef std::unordered_map<string> hashSet;

    bool isPali(string s)
    {
        string srev = s;
        reverse(srev.begin(), srev.end());
        return ( s == srev );
    }


    int doMinCut(string s, hashMap &map, hashMap &palis)
    {
        int ret = s.length() - 1;
        if ( isPali(s) ) 
        {
            map.insert( {s, 0} );
            return 0;
        }
        for (int leftLength = 1; leftLength <= s.length(); leftLength++)
        {
            string left,right;
            left = s.substr(0, leftLength);
            right = s.substr(leftLength, s.length() - leftLength);
            if ( palis.find(left) != palis.end() )
            {
                if ( map.find(right) == map.end() )
                {
                    ret = min(ret, doMinCut(right, map, palis) + 1);
                }
                else
                {
                    ret = min(ret, map[right] + 1);
                }
            }
        }
        map.insert( {s, ret} );
        return ret;
    }


    void initialPali(string s, hashSet &set)
    {
        for (int len = 1; len <= s.length(); len++)
        {
            for (int idx = 0; idx <= s.length() - len; idx++)
            {
                string cur= s.substr(idx, len);
                if ( isPali(cur) ) set.insert(cur);
            }
        }
    }


    void initialPali(string s, vector< vector<bool> > &lookUpTable)
    {
        for (int i = 0 ; i < s.length(); i++)
        {
            lookUpTable[i][i] = true;
        }

        for (int i = 1 ; i < s.length(); i++)
        {
            lookUpTable[i-1][i] = (s[i-1] == s[i]);
        }

        for (int len = 2; len < s.length(); len++)
        {
            for (int idx = len; idx < s.length(); idx++)
            {
                if ( (s[idx-len] == s[idx]) && ( (idx-len+1) <= (idx-1) ) )
                {
                    lookUpTable[idx-len][idx] = lookUpTable[idx-len+1][idx-1];
                }
                else
                {
                    lookUpTable[idx-len][idx] = false;
                }
            }
        }
    }


    int minCutHash(string s) {
        hashMap map;
        hashSet palis;
        initialPali(s, palis);
        return doMinCut(s, map);
    }

    int minCutDp(string s)
    {
        int n = s.length();
        vector< vector<int> > table(n, vector<int>(n, n) );
        vector< vector<bool> > palitable(n, vector<bool>(n, false) );
        initialPali(s, palitable);
        for (int i = 0; i < n; i++)
        {
            table[i][i] = 0;
        }

        for (int j = 2; j <= n; j++)
        {
            for (int i = 0; i <= (n - j); i++)
            {
                if ( palitable[i][j] )
                {
                    table[i][i+j-1] = 0;
                }
                else
                {
                    for (int k = i; k < (i+j-1); k++)
                    {
                        table[i][i+j-1] = min(table[i][i+j-1], table[i][k] + table[k+1][i+j-1] + 1 );
                    }
                }
            }
        }
        return table[0][n-1];
    }

    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return minCutDp(s);
    }
};