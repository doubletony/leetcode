class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());

        int n = S.size();
        vector<int> ina;
        vector<vector<int> >  a;
        a.push_back( ina );
        for (int i = 0; i < n; i++)
        {
            int sz = a.size();
            for (int j = 0; j < sz; j++)
            {
                vector<int> tmp = a[j];
                tmp.push_back(S[i]);
                a.push_back(tmp);
            }
        }
        return a;
    }
};