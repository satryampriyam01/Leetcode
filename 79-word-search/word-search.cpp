class Solution {
public:


bool helper(vector<vector<char>>& board, string &word,string str,int i,int j,int k)
{
   // cout<<str<<" "<<word<<endl;
    if(str==word)
    {
        return 1;
    }

    if(k>word.size()-1)
    {
        return 0;
    }

    bool up=false;
    if(i-1>-1 && board[i-1][j]==word[k])
    {
                    char ch=board[i-1][j];
                    board[i-1][j]=-1;
                    up=helper(board,word,str+ch,i-1,j,k+1);
                    board[i-1][j]=ch;
    }

    bool down=false;

    if(i+1<board.size() && board[i+1][j]==word[k])
    {
                    char ch=board[i+1][j];
                    board[i+1][j]=-1;
                    down=helper(board,word,str+ch,i+1,j,k+1);
                    board[i+1][j]=ch;
    }

    bool left=false;

    if(j-1>-1 && board[i][j-1]==word[k])
    {
                char ch=board[i][j-1];
                    board[i][j-1]=-1;
                    left=helper(board,word,str+ch,i,j-1,k+1);
                    board[i][j-1]=ch;
    }

    bool right=false;

    if(j+1<board[0].size() && board[i][j+1]==word[k])
    {
                    char ch=board[i][j+1];
                    board[i][j+1]=-1;
                    up=helper(board,word,str+ch,i,j+1,k+1);
                    board[i][j+1]=ch;
    }

    return up+down+left+right;



}


    bool exist(vector<vector<char>>& board, string word) {
        

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j])
                {
                    char ch=board[i][j];
                    board[i][j]=-1;
                    string str;
                    bool isTrue=helper(board,word,str+ch,i,j,1);
                    if(isTrue)
                    {
                        return 1;
                    }
                    board[i][j]=ch;
                }
            }
        }
        return 0;



    }
};