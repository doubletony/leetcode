
class Solution {
public:

    int getSmallerCounter(int A[], int n, int val)
    {
        // counter the number that is strictly smaller than val
        int start = 0;
        int end = n - 1;
        int counter = -1;
        while ( start <= end )
        {
            int mid = (start + end) / 2;
            if ( A[mid] >= val)
            {
                end = mid - 1;
            }
            else if ( A[mid] < val)
            {
                counter = mid;
                start = mid + 1;
            }
        }
        return counter + 1;
    }

    int findKinArray(int A[], int m, int B[], int n, int k, bool &status)
    {
        int start, end;
        start = 0;
        end = m - 1;
        int ret = -1;
        while (  start <= end)
        {
            int mid = (start+end)/ 2;
            int va = A[mid];
            int counterA = getSmallerCounter(A, m, va) + getSmallerCounter(B, n, va);
            if ( counterA == (k-1))
            {
                status = true;
                return va;
            }
            else if ( counterA >= k)
                end = mid - 1;
            else
            {
                ret = A[mid];
                start = mid + 1;
            }
        }
        status = false;
        return ret;
    }

    int findKth(int A[], int m, int B[], int n, int k)
    {
        int ra,rb;
        bool ba,bb;
        ra = findKinArray(A,m,B,n,k,ba);
        rb = findKinArray(B,n,A,m,k,bb);
        if ( bb ) return rb;
        if ( ra == -1) return rb;
        if ( ra < rb ) return rb;
        return ra;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if ( ( (m+n) % 2) != 0)
            return double( findKth(A,m,B,n, (m+n+1)/2) ) ;
        else
            return 0.5 * (double( findKth(A,m,B,n, (m+n)/2) ) + double( findKth(A,m,B,n, (m+n)/2 + 1) )) ;
    }
};