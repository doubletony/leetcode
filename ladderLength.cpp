class Solution {
public:
    bool changeable(string a, string b)
    {
        if ( a.length() != b.length() )
        {
            return false;
        }
        int counter = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if ( a[i] != b[i] )
            {
                counter++;
            }
        }

        if (counter == 1)
        {
            return true;
        }
        return false;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // special case
        if ( start == end)
        {
            unordered_set<string>::iterator iter;
            for (iter = dict.begin(); iter != dict.end(); iter++)
            {
                if (start == (*iter) )
                {
                    continue;
                }
                if ( changeable( start, *iter) )
                {
                    return 3;
                }
            }
            return 0;
        }

        queue< string > q;
        unordered_set<string> usedWord;
        usedWord.insert(start);
        q.push(start);
        int length = 1;
        while ( ! q.empty() )
        {
            int size = q.size();
            length++;
            for (int i = 0; i < size; i++)
            {
                string tmp = q.front();
                q.pop();
                for (int idx = 0; idx < tmp.length(); idx++)
                {
                    for (int dx = 0; dx < 26; dx++)
                    {
                        string tmp2 = tmp;
                        tmp2[idx] = 'a' + dx;
                        if ( (usedWord.find( tmp2 ) == usedWord.end()) && 
                             (dict.find( tmp2 ) != dict.end()))
                        {
                            // not visited, try to expand
                            if ( (tmp2) == end)
                            {
                                return length;
                            }
                            q.push( tmp2 );
                            usedWord.insert( tmp2 );
                        }
                    }
                    
                }
            }
        }

        return 0;
    }
};