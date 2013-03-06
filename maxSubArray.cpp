class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int currMax;
        int maxVal = 0;
        int i = 0;
        for ( ; i < n; i++)
        {
            if ( A[i] > 0)
            {
                currMax = A[i];
                maxVal = currMax; // Bug 1: don't forget to initial the maxVal. 
                i++;              // Bug 2: don't forget increase the index
                break;
            }
        }
        if ( i >= n )
        {
            // all negative
            currMax = A[0];
            for ( i = 1; i < n; i++)
            {
                if ( A[i] > currMax)
                {
                    currMax = A[i];
                }
            }

            return currMax;
        }
        
        // well, at least, we found one positive number.

        for (; i < n; i++)
        {
            if ( A[i] >= 0 )
            {
                currMax += A[i];
            }
            else if ( A[i] < 0)
            {
                if (currMax >= maxVal)
                {
                    maxVal = currMax;
                }
                
                if ( ( A[i] + currMax) >= 0)
                {
                    currMax += A[i];
                }
                else
                {
                    currMax = 0;
                }
            }
        }

        // Bug 3: don't forget update the last maxVal
        if (currMax >= maxVal)
        {
            maxVal = currMax;
        }

        return maxVal;
    }
};