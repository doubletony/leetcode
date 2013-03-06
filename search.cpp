class Solution {
public:


    //////////////////////////////////////////////////////////////////////////
    
    // if we have duplicated values.
    //int gotPivot(int A[], int n, int target)
    //{
    //    for(int i = 0; i <n-1;i++)
    //    {
    //        if( A[i] > A[i+1] )
    //            return i;
    //    }

    //    return -1; // no need to rotattion
    //}

    //////////////////////////////////////////////////////////////////////////
    int gotPivot(int A[], int n, int target)
    {
        if ( n <= 1)
        {
            return -1;
        }

        int front, back;
        front = 0;
        back = n - 1;
        int mid;
        int header = A[0];
        while ( front <= back)
        {
            mid = front + (back - front )/ 2;

            if ( (mid+1) < n)
            {
                if ( A[mid] > A[mid+1] )
                {
                    return mid;
                }
            }

            if ( A[mid] <= header )
            {
                back = mid - 1;
            }
            else
            {
                front = mid + 1;
            }
        }

        return -1; // no need to rotattion
    }

    int bstpivot(int A[], int n, int target, int pivot)
    {
        int front,back,mid;
        front = 0;
        back = n - 1;
        while (front <= back)
        {
            mid = front + (back - front) / 2;
            if ( A[ (mid+pivot) % n ] == target )
            {
                return (mid+pivot) % n;
            }
            
            if ( A[ (mid+pivot) % n ] < target )
            {
                front = mid + 1;
            }
            else
            {
                back = mid - 1;
            }
        }
        return -1;
    }


    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int piv = gotPivot(A, n, target);
        if (piv == -1)
        {
            piv = 0;
        }
        else
        {
            piv++;
        }

        return bstpivot(A, n, target, piv);

    }
};

