class Solution {
public:


    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if ( m == 0)
        {
            return false;
        }
        int n = matrix[0].size();

        int start, mid, end;
        start = 0;
        end = m*n-1;
        
        while (start<=end)
        {
            mid = (start+end)/2;
            int i,j;
            i = mid/n;
            j = mid%n;

            if (matrix[i][j]==target)
                return true;

            if (matrix[i][j]<target)
                start = mid+1;
            else 
                end = mid-1;
        }
        return false;
    }
};