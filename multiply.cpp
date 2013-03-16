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

    string add(string num1, string num2) 
    {
        string ret;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int idx = 0;
        int carry = 0;
        while ( (idx < num1.length()) || (idx < num2.length() ) )
        {   
            int a, b;
            a = b = 0;
            if ( idx < num1.length())
                a = (num1[idx] - '0');
            if ( idx < num2.length())
                b = (num2[idx] - '0');

            int sum =  a + b + carry;
            ret.push_back( (sum % 10 ) + '0' );
            carry = sum / 10;
            idx++;
        }
        if ( carry == 1)
        {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string cleanZero( string str)
    {
        int zerocoun = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0')
                zerocoun++;
            else
                break;
        }

        return str.substr( zerocoun, str.length() - zerocoun );
    }

    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( isZero(num1) || isZero(num2) )
        {
            return "0";
        }

        if ( num1.length() == 1 && num2.length() == 1)
        {
            int a, b;
            a = num1[0] - '0';
            b = num2[0] - '0';
            int ret = a * b;
            string res;
            if ( ret >= 10)
            {
                res.push_back( '0' + (ret/10) );
            }
            res.push_back( '0' + (ret%10));
            return res;
        }

        if ( num1.length() < num2.length())
        {
            return multiply( num2, num1);
        }

        if ( num1.length() > num2.length() )
        {
            string num1right = num1.substr( num1.length() - num2.length(), num2.length() ); // right half
            string num1left = num1.substr(0, num1.length() - num2.length());
            string ret1, ret2;
            ret1 = multiply( num1right, num2 );
            ret2 = multiply( num1left, num2 ) + string(num2.length(), '0');
            return add(ret1, ret2);
        }

        // equal length
        int mid = num1.length() / 2;
        int n = num1.length();
        string num1right =  cleanZero( num1.substr( mid, n - mid ) );
        string num1left =  num1.substr( 0, mid );

        string num2right =  cleanZero( num2.substr( mid, n - mid ) );
        string num2left=  num2.substr( 0, mid );

        string ll, lr, rl, rr;
        string lrrl;
        string result;
        ll = multiply(num1left, num2left );
        lr = multiply(num1left, num2right );
        rl = multiply(num1right, num2left );
        rr = multiply(num1right, num2right );

        ll = ll + string( (n - mid)*2, '0');
        lrrl = add(lr, rl);
        lrrl = lrrl + string( (n - mid), '0');
        result = add( ll, lrrl );
        result = add(result, rr);
        return result;
    }
};