class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (n == 0)
        {
            return 0;
        }

        int writeLoc;
        writeLoc = 1;
        for (int i = 1; i < n; i++)
        {
            if ( A[i] != A[i-1])
            {
                A[writeLoc] = A[i];
                writeLoc++;
            }
        }

        return writeLoc;
    }
};