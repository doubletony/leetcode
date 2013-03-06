class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (digits.size() == 0)
        {
            vector<int> a;
            return a;
        }

        reverse(digits.begin(), digits.end());
        int carry = 0;
        digits[0] += 1;
        for (int i = 0; i < digits.size(); i++)
        {
            int tmpv = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = tmpv;
        }
        if (carry > 0)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};