class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int front, back, mid;
        front = 0;
        back = n - 1;
        while ( front <= back)
        {
            mid = (front + back) / 2;
            if ( A[mid] == target)
            {
                return mid;
            }

            if (A[mid] < target)
            {
                front = mid+1;
            }
            else
            {
                back = mid - 1;
            }
        }

        return front;
    }
};