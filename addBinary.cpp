class Solution {
public:

    void reverseChar(char * str, int length)
    {
        int middle = (length+1)/2;
        for (int i = 0; i < middle; i++)
        {
            char tmp = str[i];
            str[i] = str[length - i];
            str[length - i] = tmp;
        }
    }

    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lenth = ( ( a.length() > b.length() ) ? a.length() : b.length() ) + 2;
        char * sumStr = new char[lenth];
        int index = 0;
        string::reverse_iterator rita = a.rbegin();
        string::reverse_iterator ritb = b.rbegin();
        char carry = 0;
        for ( ; (rita < a.rend()) || (ritb < b.rend());)
        {
            char ca,cb;
            ca = '0';
            cb = '0';

            if (rita < a.rend()) ca = (*rita);
            if (ritb < b.rend()) cb = (*ritb);
            
            int ia,ib;
            ia = ca - '0';
            ib = cb - '0';
            if ( (ia + ib + carry) > 1 )
            {
                sumStr[index] = '0' + ( (ia + ib + carry) %2);
                carry = 1;
            }
            else
            {
                sumStr[index] = '0' + ( (ia + ib + carry) %2);
                carry = 0;
            }

            index++;
            if (rita < a.rend()) rita++;
            if (ritb < b.rend()) ritb++;
        }

        if ( carry > 0 ) 
        {
            sumStr[index] = '1';
            index++;
        }
        //reverseChar(sumStr, index);
        //sumStr[index] = '\0';
        string rsl;
        for (int i = index - 1; i >= 0; i--)
        {
            rsl.append(1, sumStr[i]);
        }
        delete [] sumStr;
        return rsl;
    }
};