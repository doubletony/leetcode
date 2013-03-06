class Solution {
public:

    void allpermute(vector<vector<int> > &rslt, vector<int> &num, int dep, int maxdep, int * a, int * status)
    {
        if ( dep == maxdep)
        {
            vector<int> newtmp;
            for (int i = 0; i < num.size(); i++)
            {
                newtmp.push_back( num[a[i]]  );
            }

            rslt.push_back(newtmp);
            return ;
        }

        for (int i = 0; i < num.size(); i++)
        {
            if (status[i] == 0)
            {
                status[i] = 1;
                a[dep] = i;
                allpermute(rslt, num, dep+1, maxdep, a, status);
                status[i] = 0;
            }
        }

    }

    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rslt;
        int staus[15];
        int a[15];
        for (int i = 0; i < 15; i++)
        {
            staus[i] = 0;
            a[i] = i;
        }

        allpermute(rslt, num, 0, num.size(), a, staus);
        return rslt;
    }
};