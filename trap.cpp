class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> leftMax, rightMax;
        leftMax.resize(n);
        rightMax.resize(n);

        int maxval = -1;
        for (int i = 0; i < n; i++)
        {
            if ( A[i] > maxval)
            {
                maxval = A[i];
            }
            leftMax[i] = maxval;
        }

        maxval = -1;
        for (int i = n - 1; i >=0 ; i--)
        {
            if ( A[i] > maxval)
            {
                maxval = A[i];
            }
            rightMax[i] = maxval;
        }

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += max(0,  min(leftMax[i], rightMax[i]) - A[i] );
        }
        return total;
    }
};