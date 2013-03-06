class Solution {
public:

    int bst(int A[], int n, int target)
    {
        int front, mid, end;
        front = 0;
        end = n-1;
        while ( front <= end)
        {
            mid = (end + front)/2;

            if ( A[mid] == target)
                return mid;

            if ( A[mid] < target)
            {
                front = mid + 1;
            }
            else
            {
                end = mid -1;
            }
        }

        return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int id = bst(A,n,target);
        vector<int> a;
        if (id != -1)
        {
            int start,end;
            start = end = id;
            while ( start >= 1)
            {
                if (A[start-1] != target)
                {
                    break;
                }
                start--;
            }

            if (A[0] == target)
            {
                start = 0;
            }

            while ( end < n-2)
            {
                if (A[end+1] != target)
                {
                    break;
                }
                end++;
            }

            if (A[n-1] == target)
            {
                end = n-1;
            }
            a.push_back(start);
            a.push_back(end);
        }
        else
        {
            a.push_back(-1);
            a.push_back(-1);
        }

        return a;
    }
};