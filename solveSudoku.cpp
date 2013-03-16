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

    vector<char> getValidMoves(vector<vector<char> > &board, int row, int col)
    {
        vector<int> marker(10, 0);
        vector<char> validmove;
        for (int i = 0; i < 9; i++)
        {
            if ( board[i][col] != '.' )
            {
                marker[ board[i][col] - '0' ] = 1;
            }

            if ( board[row][i] != '.' )
            {
                marker[ board[row][i] - '0' ] = 1;
            }
        }
        // check 3 by 3
        int starti, startj;
        starti = row / 3;
        startj = col / 3;
        for (int i = starti * 3; i < starti * 3 + 3; i++)
        {
            for (int j = startj * 3; j < startj * 3 + 3; j++)
            {
                if ( board[i][j] != '.' )
                {
                    marker[ board[i][j] - '0' ] = 1;
                }
            }
        }

        for (int i = 1; i <= 9; i++)
        {
            if ( marker[i] != 1)
            {
                validmove.push_back( i + '0');
            }
        }

        return validmove;
    }

    void solveSudoku(vector<vector<char> > &board)
    {
        solveSudokuDoThing(board);
    }

    bool solveSudokuDoThing(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row, col; // find an empty slot
        bool stop = false;
        for (int i = 0; (i < 9) && !stop; i++)
        {
            for (int j = 0; (j < 9) && !stop; j++)
            {
                if ( board[i][j] == '.')
                {
                    stop = true;
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        if ( !stop )
        {
            return true;
        }

        vector<char> moves = getValidMoves(board, row, col);

        for (int i = 0; i < moves.size(); i++)
        {
            board[row][col] = moves[i];
            if ( isValidSudoku(board) )
            {
                if( solveSudokuDoThing(board) )
                    return true;
            }
        }
        board[row][col] = '.';
        return false;
    }
};