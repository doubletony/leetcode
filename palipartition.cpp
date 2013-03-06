class Solution {
public:

    bool isPali(string s)
    {
        string srev = s;
        reverse(srev.begin(), srev.end());
        return ( s == srev );
    }

    vector< vector<string> > doPart(string s)
    {
        vector< vector<string> > ret;
        for (int leftLength = 1; leftLength < s.length(); leftLength++)
        {
            string left,right;
            left = s.substr(0, leftLength);
            right = s.substr(leftLength, s.length() - leftLength);
            if ( isPali(left) )
            {
                vector< vector<string> > tmp = doPart(right);
                for (int i = 0; i < tmp.size(); i++)
                {
                    vector<string> tmpS;
                    tmpS.push_back(left);
                    for (int j = 0; j < tmp[i].size(); j++)
                    {
                        tmpS.push_back( tmp[i][j] );
                    }
                    ret.push_back(tmpS);
                }
            }
        }
        if ( isPali(s) ) 
        {
            vector<string> tmpS;
            tmpS.push_back(s);
            ret.push_back(tmpS);
        }
        return ret;
    }

    vector< vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<string> > ret;
        ret = doPart(s);
        return ret;
    }
};