class Solution {
public:

    vector<int> sortit(vector<int> &numbers)
    {
        vector<int> tmp;
        tmp = numbers;
        sort( tmp.begin(), tmp.end() );
        return tmp;
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tmp = sortit(numbers);

        int front, back;
        front = 0; back = tmp.size() - 1;

        while ( front < back)
        {
            if (  tmp[front] + tmp[back] == target)
            {
                break;
            }

            if ( tmp[front] + tmp[back] > target )
            {
                back--;
            }
            else
            {
                front++;
            }
        }

        int index1,index2;
        int n = numbers.size();
        for (int i = 0; i < numbers.size(); i++)
        {
            if ( numbers[i] == tmp[front])
            {
                index1 = i + 1;
            }

            if ( numbers[n -1 -i] == tmp[back])
            {
                index2 = n -i;
            }
        }

        vector<int> ret;
        if ( index1 > index2)
        {
            ret.push_back(index2);
            ret.push_back(index1);
        }
        else
        {
            ret.push_back(index1);
            ret.push_back(index2);
        }
        return ret;
    }
};