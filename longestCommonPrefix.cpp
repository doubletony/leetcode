class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string lcp = "";

        if (strs.size() == 0)
        {
            return lcp;
        }

        int idx = 0;
        int length = strs[0].length();

        for (int i = 1; i < strs.size(); i++)
        {
            if (strs[i].length() < length)
            {
                idx = i;
                length = strs[i].length();
            }
        }

        lcp = strs[idx].substr(0,length);
        for (int i = 0; i < length; i++)
        {
            bool stop = false;
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[idx][i])
                {
                    stop = true;
                }
            }
            if (stop)
            {
                lcp = strs[idx].substr(0,i);
                break;
            }
        }
        return lcp;
    }
};