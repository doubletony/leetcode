
class Solution {
public:

    void reverse(vector<int> &num, int start, int end)
    {
        int n = end - start + 1;
        for (int i = 0; i < n / 2; i++)
        {
            int tmp = num[start+i];
            num[start+i] = num[end - i];
            num[end - i] = tmp;
        }
        
    }

    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = num.size();
        if ( n <= 1 )
        {
            return;
        }

        if ( n == 2)
        {
            int tmp = num[0];
            num[0] = num[1];
            num[1] = tmp;
            return ;
        }

        int last = n - 2;
        while( last >= 0)
        {
            if ( num[last] < num[last+1] )
            {
                break;
            }
            else
            {
                last--;
            }
        }

        if (last < 0)
        {
            reverse(num, 0, n - 1);
            return ;
        }

        int swapID = n - 1;
        while( num[swapID] <= num[last] )
        {
            swapID--;
        }

        int tmp = num[last];
        num[last] = num[swapID];
        num[swapID] = tmp;
        reverse(num, last+1, n - 1);

    }
};

