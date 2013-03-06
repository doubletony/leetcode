class Solution {
public:
        
    int getNumOfSmaller(int a[], int n, int val)
    {
        // return the number of elements that are smaller than val
        if ( n == 0)
        {
            return 0;
        }
        if ( n == 1 )
        {
            if ( val >= a[0])
            {
                return 1;
            }
        }

        if ( n == 2)
        {
            if ( val >= a[1])
            {
                return 2;
            }

            if ( val >= a[0])
            {
                return 1;
            }
            return 0;
        }

        int start = 0;
        int end = n -1;
        int mid = (start + end) / 2;
        while ( start < end )
        {
            if ( a[mid] > val)
            {
                end = mid;
            }
            else if ( a[mid] <= val)
            {
                start = mid;
            }

            mid = (start + end) / 2;
        }

        if ( a[mid] > val)
        {
            if (mid == 0)
                return 0;
            else
                return mid - 1;
        }
        else
        {
            return mid;
        }

    }

    int searchInOneArray(int A[], int m, int B[], int n, int k)
    {
        //return the val if found the idx of k-the element, otherwise, return -1;
        // and always searching in the array A.
        int cAA, cAB;
        int idxA;
        int start, end;
        start = 0;
        end = m - 1;
        idxA = m /2;
        int endIDA = m;
        int endIDB = n;
        if ( m > 0)
        {
            while(start < end)
            {
                cAA = getNumOfSmaller(A, endIDA, A[idxA]);
                cAB = getNumOfSmaller(B, endIDB, A[idxA]);
                if ( cAA + cAB > k)
                {
                    endIDA = cAA;
                    endIDB = cAB;
                    end = idxA;
                    idxA = (start + end) / 2;
                }
                else if ( cAA + cAB < k )
                {
                    start = idxA;
                    idxA = (start + end) / 2;
                }
                else
                {
                    // found it
                    return idxA;
                }
            }
        }
        else
        {
            return -1;
        }
        return -1;
    }

    int findKelement(int A[], int m, int B[], int n, int k)
    {
        int idx = searchInOneArray(A, m, B, n, k);
        if (idx != -1)
        {
            return A[idx];
        }

        idx = searchInOneArray(B, n, A, m, k);
        if (idx != -1)
        {
            return B[idx];
        }
        return -1; // what the hell?
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if ( ( (m + n) % 2 ) == 1)
        {
            int k = (m+n+1) / 2;
            return double(findKelement(A,  m, B, n, k)  );
        }
        else
        {
            int k = (m+n) / 2;
            int m1, m2;
            m1 = findKelement(A,  m, B, n, k);
            m2 = findKelement(A,  m, B, n, k - 1);
            return (m1*1.0 + m2*1.0) / 2.0;
        }
    }
};