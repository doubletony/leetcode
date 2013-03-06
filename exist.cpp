class Solution {
public:

    bool isvalid(vector<vector<char> > &board, int row, int col, vector<vector<int> > &st, string word, int idx)
    {
        if ( idx >= word.length())
        {
            return true;
        }

        if ( row < 0)
        {
            return false;
        }

        if ( row >= board.size())
        {
            return false;
        }

        if ( col < 0)
        {
            return false;
        }

        if ( col >= board[0].size() )
        {
            return false;
        }
        if ( st[row][col] == 1 )
        {
            return false;
        }

        if ( board[row][col] != word[idx] )
        {
            return false;
        }

        st[row][col] = 1;
        if ( isvalid(board, row - 1, col, st, word, idx+1) )
        {
            return true;
        }
        else if ( isvalid(board, row + 1, col, st, word, idx+1) )
        {
            return true;
        }
        else if ( isvalid(board, row, col - 1, st, word, idx+1) )
        {
            return true;
        }
        else if ( isvalid(board, row, col + 1, st, word, idx+1) )
        {
            return true;
        }
        else
        {
            st[row][col] = 0;
            return false;
        }
    }

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.size() == 0)
        {
            return false;
        }

        vector< vector<int> > status( board.size(), vector<int> ( board[0].size(), 0 ) );
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ( isvalid(board, i,j, status, word, 0) )
                    return true;
            }
        }

        return false;
    }
};