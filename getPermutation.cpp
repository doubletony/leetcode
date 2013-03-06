class Solution {
public:

    void doIt(int * a, int dep, int maxdep, int * status, int &counter, int maxC)
    {
        if (counter == maxC)
        {
            return ;
        }

        if ( dep == maxdep)
        {
            // judge 
            counter++;
            return ;
        }

        for (int i = 0; i < maxdep; i++)
        {
            if (status[i] == 0)
            {
                status[i] = 1;
                a[dep] = i+1;
                doIt(a, dep+1, maxdep, status, counter, maxC);
                status[i] = 0;
            }
            if (counter == maxC)
            {
                return ;
            }
        }
    }

    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a[10];
        int stauts[10];
        for (int i = 0 ; i<10;i++)
        {
            stauts[i] = 0;
            a[i] = i;
        }
        int counter = 0;
        doIt(a, 0, n, stauts, counter, k);
        string resutl;
        for (int i = 0; i < n; i++ )
        {
            resutl.push_back('0'+a[i] - 0);
        }
        return resutl;
    }
};