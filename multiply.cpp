class Solution {
public:
    bool isZero(string num1)
    {
        for (int i = 0; i < num1.length(); i++)
        {
            if ( num1[i] != '0')
            {
                return false;
            }
        }
        return true;
    }

    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( isZero(num1) || isZero(num2) )
        {
            return "0";
        }


    }
};