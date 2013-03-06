class Solution {
public:
    int jump_backward(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int * counter = new int [n];
        counter[n-1] = 0;
        for (int i = n-2; i >= 0; i--)
        {
            int minStep = 1e5;
            for (int j = 1; j <= A[i]; j++)
            {
                if ( (i+j) < n )
                {
                    if ( minStep > (1+counter[i+j]) )
                    {
                        minStep = 1+counter[i+j];
                    }
                }
            }
            counter[i] = minStep;
        }
        int relt = counter[0];
        delete [] counter;
        return relt;
    }

    int jump_forward(int A[], int n) 
    {
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
                    if ( (counter[i+j] > counter[i]+1) || (counter[i+j] == -1))
                    {
                        counter[i+j] = counter[i]+1;
                    }
                }
            }

            if ( counter[n-1] != -1)
            {
                break;
            }
        }
        int relt = counter[n-1];
        delete [] counter;
        return relt;
    }

    int jump_best(int A[], int n) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+A[i]);
        }

        return ret;
    }

    int jump(int A[], int n) 
    {
        int * counter = new int [n];
        for (int i = 0; i < n; i++)
        {
            counter[i] = -1;
        }

        counter[0] = 0;
        while ( counter[n-1] == -1)
        {

        }

    }

};