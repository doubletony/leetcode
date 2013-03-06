
struct StringWithIndexNode
{
    string str;
    int index;
    StringWithIndexNode (string str_in, int idx) : str(str_in), index(idx) {};
};

struct StringWithIndexNodeCompare {
    bool operator() (StringWithIndexNode i, StringWithIndexNode j) { return (i.str < j.str );}
} StringWithIndexCompare;

class Solution {
public:
    
    string sortOneString( string str)
    {   
        vector<char> svec;
        for (int i = 0; i < str.length(); i++)
        {
            svec.push_back( str[i] );
        }

        sort(svec.begin(), svec.end());
        string sortedstr;
        for (int i = 0; i < svec.size(); i++ )
        {
            sortedstr.push_back(svec[i]);
        }
        return sortedstr;
    }

    vector<StringWithIndexNode> getSortedEachWordWithIndex(vector<string> &strs)
    {
        vector<StringWithIndexNode> swin;
        for (unsigned int i = 0; i < strs.size(); i++)
        {
            string sorted = sortOneString(strs[i]);
            swin.push_back( StringWithIndexNode(sorted, i) );
        }
        sort(swin.begin(), swin.end(), StringWithIndexCompare);
        return swin;
    }

    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string>  res;
        if (strs.size() < 1)
        {
            return res;
        }
        vector<StringWithIndexNode> swin = getSortedEachWordWithIndex(strs);
        StringWithIndexNode cur = swin[0];

        int count = 1;
        bool find_anagram = false;
        for (int i = 1; i < swin.size(); i++)
        {
            if ( swin[i].str == cur.str )
            {
                res.push_back( strs[swin[i].index] );
                find_anagram = true;
            }
            else
            {
                if ( find_anagram )
                {
                    res.push_back( strs[cur.index] );
                }
                cur = swin[i];
                find_anagram = false;
            }
        }
        if ( find_anagram )
        {
            res.push_back( strs[cur.index] );
        }
        return res;
    }
};