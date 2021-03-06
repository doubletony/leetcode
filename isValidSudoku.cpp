class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if ( !( (board[i][j] <= '9' && board[i][j] >= '0') || board[i][j] == '.' ))
                {
                    return false;
                }
            }
        }

        // check row
        for (int i = 0; i < 9; i++)
        {
            vector<int> marker(10, 0);
            for (int j = 0; j < 9; j++)
            {
                if ( (board[i][j] <= '9' && board[i][j] >= '0') )
                {
                    int idx = board[i][j] - '0';
                    if ( marker[idx] == 1)
                    {
                        return false;
                    }
                    else
                        marker[idx] = 1;
                }
            }
        }

        // check col
        for (int j = 0; j < 9; j++)
        {
            vector<int> marker(10, 0);
            for (int i = 0; i < 9; i++)
            {
                if ( (board[i][j] <= '9' && board[i][j] >= '0') )
                {
                    int idx = board[i][j] - '0';
                    if ( marker[idx] == 1)
                    {
                        return false;
                    }
                    else
                        marker[idx] = 1;
                }
            }
        }

        // check each 3 by 3 cube;

        for (int starti = 0; starti < 3; starti++ )
        {
            for (int startj = 0; startj < 3; startj++)
            {
                vector<int> marker(10, 0);
                for (int i = starti*3; i < starti*3+3; i++)
                {
                    for (int j = startj*3; j < startj*3+3; j++)
                    {
                        if ( (board[i][j] <= '9' && board[i][j] >= '0') )
                        {
                            int idx = board[i][j] - '0';
                            if ( marker[idx] == 1)
                            {
                                return false;
                            }
                            else
                                marker[idx] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};