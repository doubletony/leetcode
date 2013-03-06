class Solution {
public:


    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> gc;
        if (n == 0)
        {
           gc.push_back(0);
           return gc;
        }

        int sz = 1<<n;
        gc.resize(sz);
        gc[0] = 0;
        gc[1] = 1;

        sz = 2;
        for (int i = 1; i < n; i++)
        {
            int adder = 1<<i;
            for (int k = 0; k < sz ; k++)
            {
                gc[sz+k] = gc[sz -k-1] + adder;
            }
            sz = sz << 1;
        }

        return gc;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        for(int i = 0; i < (1<<n); i++ )
            ret.push_back( (i>>1) ^ i );
            
        return ret;
    }
};