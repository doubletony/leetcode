class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( x == 0 || x == 1)
        {
            return x;
        }

        int front, back, mid;

        front = 0; back = x;
        while ( front <= back)
        {
            mid = (front + back) / 2;
            if ( ( mid  == (x/mid) ))
            {
                return mid;
            }

            if (  (mid) < (x/mid) )
            {
                front = mid + 1;
            }
            else
            {
                back = mid -1;
            }
        }

        if ( mid < (x/mid))
        {
            return mid;
        }
        else
        {
            return mid-1;
        }
    }
};