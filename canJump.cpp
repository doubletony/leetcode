class Solution {
public:
    bool canJump_forward(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int * counter = new int [n];
        for (int i = 0; i < n; i++)
        {
            counter[i] = -1;
        }
        counter[0] = 0;

        for (int i  = 0; i<n ; i++)
        {
            for (int j = 1; j <= A[i]; j++)
            {
                if ( (i+j) < n )
                {
                    if ( (counter[i] != -1) )
                    {
                        if ( (counter[i+j] > counter[i]+1) || (counter[i] != -1) )
                        {
                            counter[i+j] = counter[i]+1;
                        }
                    }
                }
            }

            if ( counter[n-1] != -1)
            {
                break;
            }
        }
        int relt = counter[n-1];
        if (relt == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool canJump(int A[], int n) {

        if (n == 0 || n == 1)
        {
            return true;
        }
        
        if ( A[0] == 0)
        {
            return false;
        }

        int last;
        last = A[0];
        for (int i =0; i < n; i++)
        {
            if ( i <= last)
            {
                if ( (i+A[i]) > last )
                {
                    last = i + A[i];
                }
            }
        }
        if ( last >= (n-1))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};