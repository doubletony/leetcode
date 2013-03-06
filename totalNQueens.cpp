

class Solution {
public:
    // n queens

    void getValidMoves( vector<int> &moves, vector<int> & status, int size)
    {
        
        vector<int> marker(size, 0);
        int curRow = status.size();

        for (int i = 0; i < status.size(); i++)
        {
            int loc = status[i];
            marker[loc] = 1; // be attacked in same col....
            // check diagonal
            loc = status[i] + (curRow - i);
            if( loc < size) marker[loc] = 1;

            loc = status[i] - (curRow - i);
            if( loc >= 0) marker[loc] = 1;
        }

        for (int i = 0; i < marker.size(); i++)
        {
            if ( marker[i] == 0)
            {
                moves.push_back(i);
            }
        }
    }

    void countNQueen(vector<int> & status, int size, int &counter)
    {
        int row = status.size();
        moves[row].clear();
        getValidMoves( moves[row], status, size);
        if ( status.size() == (size - 1) )
        {
            // last queen, all moves count on.
            counter += moves[row].size();
            return ;
        }
        for (int i = 0; i < moves[row].size(); i++)
        {
            status.push_back( moves[row][i] );
            countNQueen(status, size, counter);
            status.pop_back();
        }
    }

    vector< vector<int> > moves;


    int totalNQueens(int n)
    {
        //if ( n == 12 ) return 14200;
        moves.clear();
        for (int i = 0; i < n; i++)
        {
            moves.push_back( vector<int> (n,0) );
        }
        vector<int> status;
        int counter = 0;
        countNQueen(status, n, counter);
        return counter;
    }

};