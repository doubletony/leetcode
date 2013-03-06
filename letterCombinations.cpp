class Solution {
public:
    
    void processQueue(queue<string> &que, string qtop, char dig )
    {
        if (dig == '2')
        {
            que.push( qtop+'a');
            que.push( qtop+'b');
            que.push( qtop+'c');
        }

        if (dig == '3')
        {
            que.push( qtop+'d');
            que.push( qtop+'e');
            que.push( qtop+'f');
        }

        if (dig == '4')
        {
            que.push( qtop+'g');
            que.push( qtop+'h');
            que.push( qtop+'i');
        }

        if (dig == '5')
        {
            que.push( qtop+'j');
            que.push( qtop+'k');
            que.push( qtop+'l');
        }

        if (dig == '6')
        {
            que.push( qtop+'m');
            que.push( qtop+'n');
            que.push( qtop+'o');
        }
        if (dig == '7')
        {
            que.push( qtop+'p');
            que.push( qtop+'q');
            que.push( qtop+'r');
            que.push( qtop+'s');
        }

        if (dig == '8')
        {
            que.push( qtop+'t');
            que.push( qtop+'u');
            que.push( qtop+'v');
        }

        if (dig == '9')
        {
            que.push( qtop+'w');
            que.push( qtop+'x');
            que.push( qtop+'y');
            que.push( qtop+'z');
        }
    }

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> rst;
        queue<string> que;
        int len = digits.length();
        que.push("");
        for (int i = 0; i < len; i++)
        {
            int qsize = que.size();
            for (int j = 0; j < qsize; j++)
            {
                string qtop = que.front();
                que.pop();
                processQueue(que, qtop, digits[i]);
            }
        }

        while ( !que.empty())
        {
            string qtop = que.front();
            que.pop();
            rst.push_back(qtop);
        }
        return rst;
    }
};