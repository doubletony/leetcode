class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = 0;
        vector<string> tmp;
        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            if (  ( length + words[i].length() + tmp.size() ) <= L )
            {
                tmp.push_back( words[i] );
                length += words[i].length();
            }
            else
            {
                // generate new line
                int spaceSize = L - length;
                string rst;
                rst = tmp[0];

                if (tmp.size() > 1)
                {
                    int avg = spaceSize / (tmp.size()-1);
                    int larsi = spaceSize % (tmp.size()-1);

                    for (int j = 1; j < tmp.size(); j++)
                    {
                        if ( j <= larsi)
                        {
                            rst = rst + string(avg+1, ' ') + tmp[j];
                        }
                        else
                        {
                            rst = rst + string(avg, ' ') + tmp[j];
                        }
                    }

                }

                if ( rst.length() < L )
                {
                    rst = rst + string( L - rst.length(), ' ');
                }
                result.push_back(rst);
                tmp.resize(0);
                length = 0;
                tmp.push_back( words[i] );
                length = words[i].length();
            }
        }

        if (tmp.size() > 0)
        {
            int spaceSize = L - length;
            string rst;
            rst = tmp[0];
            for (int j = 1; j < tmp.size(); j++)
            {
                rst = rst + string(1, ' ') + tmp[j];
            }
            if ( rst.length() < L )
            {
                rst = rst + string( L - rst.length(), ' ');
            }
            result.push_back(rst);
        }
        return result;
    }
};