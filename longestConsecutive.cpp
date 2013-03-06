class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> us;
        unordered_set<int> visited;
        us.insert(num.begin(), num.end());
        int maxLen = 0;
        for (int i = 0; i < num.size(); i++)
        {
            if ( visited.find( num[i] ) == visited.end() )
            {
                // try to expand this num
                int lenth = 1;
                bool stop = false;
                int tmp = num[i];
                while ( !stop )
                {
                    if ( tmp == INT_MIN)
                    {
                        stop = true;
                    }
                    else
                    {
                        tmp--;
                        if (  us.find( tmp ) != us.end() )
                        {
                            visited.insert(tmp);
                            lenth++;
                        }
                        else
                        {
                            stop = true;
                        }
                    }
                }

                stop = false;
                tmp = num[i];

                while ( !stop )
                {
                    if ( tmp == INT_MAX)
                    {
                        stop = true;
                    }
                    else
                    {
                        tmp++;
                        if (  us.find( tmp ) != us.end() )
                        {
                            visited.insert(tmp);
                            lenth++;
                        }
                        else
                        {
                            stop = true;
                        }
                    }
                }

                maxLen = max(maxLen, lenth);
            }
        }
        return maxLen;
    }
};