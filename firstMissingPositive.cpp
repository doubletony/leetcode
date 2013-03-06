// Given an unsorted integer array, find the first missing positive integer.
// 
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
// 
// Your algorithm should run in O(n) time and uses constant space.


// idea is simple as : Reservoir_sampling
class Solution {
public:
    void ChainChange(int A[], int n, int idx)
    {
        if ( A[idx] == ( idx+1 ) )
        {
            return ;
        }

        int tmp = A[idx];
        while ( tmp <= n && tmp > 0)
        {
            idx = tmp - 1;
            tmp = A[idx];
            A[idx] = idx + 1;
            if ( tmp == (idx+1) )
            {
                break;
            }
        }
    }

    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n ; i++)
        {
            ChainChange(A, n ,i);
        }

        int res = 1;
        for (int i = 0; i < n; i++)
        {
            if ( A[i] != (i+1))
            {
                res = i+1;
                break;
            }
            res = i+2;
        }
        return res;
    }
};