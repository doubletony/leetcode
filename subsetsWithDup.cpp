class Solution {
public:

    int getCounter(vector<int> &S, int i)
    {
        int n = S.size();

        if ( i < n)
        {
            int tmp = S[i];
            int counter = 1;
            int k = i+1;
            while ( k < n)
            {
                if( S[k] == S[i] )
                {
                    k++;
                    counter++;
                }
                else
                {
                    break;
                }
            }
            return counter;
        }
        return -1;
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());

        int n = S.size();
        vector<int> ina;
        vector<vector<int> >  a;
        a.push_back( ina );
        int i = 0;
        for ( ; i < n; )
        {
            int sz = a.size();
            int cnt = getCounter(S, i);
            for (int j = 0; j < sz; j++)
            {
                for (int k = 1; k <= cnt; k++)
                {
                    vector<int> tmp = a[j];
                    for (int l = 0; l < k; l++)
                    {
                        tmp.push_back(S[i]);
                    }
                    a.push_back(tmp);
                }
            }
            i += cnt;
        }
        return a;
    }
};