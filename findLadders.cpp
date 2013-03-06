class Solution {
public:

    void ladders(string start, string end, vector< vector<string> > &all, unordered_set<string> &checked, vector<string> &path, unordered_set<string> &dict, int depth, int maxLen)
    {
        if ( depth > maxLen)
        {
            return ;
        }

        checked.insert(start);
        for (int i = 0; i < start.length(); i++)
        {
            for (int j = 0; j < 25; j++)
            {
                string tmp = start;
                tmp[i] = 'a' + j;
                if ( dict.find(tmp) != dict.end() )
                {
                    vector<string>::iterator iter;
                    iter = find(path.begin(), path.end(), tmp);

                    if ( (tmp == end) && (depth+1 == maxLen) )
                    {
                        path.push_back( tmp );
                        all.push_back( path );
                        path.pop_back();
                    }
                    else if ( iter == path.end())
                    {
                        path.push_back( tmp );
                        ladders(tmp, end, all, checked,  path, dict, depth+1, maxLen);
                        path.pop_back();
                    }
                }
            }
        }
        return ;
    }

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

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector< vector<string> > all;
        vector< string > path;
        unordered_set<string> usedWord;
        int maxLen = ladderLength(start, end, dict);
        path.push_back(start);
        usedWord.insert();
        ladders(start, end, all, usedWord, path, dict, 1, maxLen);
        return all;
    }
};