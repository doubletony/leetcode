class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cr,cw,cb;
        cr = cw = cb = 0;
        for (int i = 0; i < n; i++)
        {
            switch( A[i] )
            {
            case 0: cr++; break;
            case 1: cw++; break;
            case 2: cb++; break;
            }
        }
        int i = 0;
        for (; i < cr; i++)
        {
            A[i] = 0;
        }

        for ( ; i < (cr+cw); i++)
        {
            A[i] = 1;
        }

        for ( ; i < (cr+cw+cb); i++)
        {
            A[i] = 2;
        }
    }
};