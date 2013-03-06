class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > a(n, vector<int>(n));
        int counter = 1;
        int diag = 0;
        while ( n > 1)
        {
            for (int i = diag; i < diag+n; i++)
            {
                a[diag][i] = counter++;
            }

            for (int i = diag+1; i < diag+n; i++)
            {
                a[i][diag+n-1] = counter++;
            }

            for (int i = diag+n-2; i >= diag; i--)
            {
                a[diag+n-1][i] = counter++;
            }

            for (int i = diag+n-2; i > diag; i--)
            {
                a[i][diag] = counter++;
            }

            n -= 2;
            diag++;
        }

        if ( n > 0)
        {
            a[diag][diag] = counter++;
        }

        return a;
    }
};