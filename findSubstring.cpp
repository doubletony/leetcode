class Solution {
public:

    bool isValid(string s, int wd, map<string, int > &target)
    {
        map<string, int > cur;
        for (int i = 0; i < s.length(); i = i + wd)
        {

            string str = s.substr( i, wd );
            if ( target.find( str) == target.end()) return false;
            cur[str] = cur[str] + 1;

            if ( cur[str] > target[str] )
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        map<string, int > target;
        int windowSize = L[0].length() * L.size();
        for (int i = 0 ; i < L.size(); i++)
        {
            target[ L[i] ] += 1;
        }

        for (int i = 0; i < S.length(); i++)
        {
            if ( (i + windowSize ) > S.length())
            {
                break;
            }

            if ( isValid( S.substr(i, windowSize), L[0].length(),  target) )
                ret.push_back(i);
        }
        return ret;
    }
};