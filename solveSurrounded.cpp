//     Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// 
//     A region is captured by flipping all 'O's into 'X's in that surrounded region .
// 
//     For example,
//     X X X X
//     X O O X
//     X X O X
//     X O X X
//     After running your function, the board should be:
// 
//     X X X X
//     X X X X
//     X X X X
//     X O X X

class Solution {
public:
    int encode(int row, int col)
    {
        return (row + 1) * 256 + (col+1);
    }

    void decode(int code, int &row, int &col)
    {
        row = ( code / 256 ) - 1;
        col = ( code % 256 ) - 1;
    }
    void markPoint(vector< vector<char> > &board, vector< vector<char> > &status, int row, int col)
    {
        if ( status[row][col] != 'O')
        {
            return ;
        }
       
        //unordered_set<int> used;
        set<int> used;
        queue< int > checkpoints;
        bool fillasX = true;
        checkpoints.push( encode(row, col) );
        while ( !checkpoints.empty() )
        {
            int code = checkpoints.front();
            checkpoints.pop();
            if ( used.find(code) == used.end() )
            {
                int rowC, colC;
                decode(code ,rowC, colC);
                if ( (rowC-1) < 0 || (colC-1) < 0 || (rowC+1) >= board.size() || (colC+1) >= board[0].size())
                {
                    // reach boundary;
                    fillasX = false;
                }
                else
                {
                    if ( status[rowC][colC] == 'O' )
                    {
                        used.insert(code);
                        if ( status[rowC-1][colC] == 'O' )
                            checkpoints.push( encode(rowC-1, colC) ) ;
                        if ( status[rowC+1][colC] == 'O' )
                            checkpoints.push( encode(rowC+1, colC) ) ;
                        if ( status[rowC][colC-1] == 'O' )
                            checkpoints.push( encode(rowC, colC-1) ) ;
                        if ( status[rowC][colC+1] == 'O' )
                            checkpoints.push( encode(rowC, colC+1) ) ;
                    }
                    else if ( status[rowC][colC] == 'E' )
                    {
                        fillasX = false;
                    }
                }

            }
        }

        //unordered_set<int>::iterator iter;
        set<int>::iterator iter;
        for ( iter = used.begin(); iter != used.end(); iter++)
        {
            int code = *iter;
            int r,c;
            decode(code ,r, c);
            if ( fillasX )
            {
                board[r][c] = 'X';
                status[r][c] = 'X';
            }
            else
            {
                status[r][c] = 'E';
            }
        }
    }

    void solve(vector< vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<char> > status = board;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                markPoint(board, status, i, j);
            }
        }
    }
};