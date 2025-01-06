class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={{false}};
        int col[9][9]={{false}};
        int result[9][9]={{false}};

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]!='.')
                {
                    char ch=board[i][j];

                    if(row[i][ch-49]!=0 || col[j][ch-49]!=0 || 
                    result[(i/3)*3+j/3][ch-49]!=0)
                    {
                        return false;
                    }
                    row[i][ch-49]=1;
                    col[j][ch-49]=1;
                    result[(i/3)*3+j/3][ch-49]=1;

                }
            }
        }

        return 1;
        
    }
};