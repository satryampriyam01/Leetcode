class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int se=0;
        int en=matrix.size()-1;

        while(se<en)
        {
            for(int i=0;i<en-se;i++)
            {
                swap(matrix[se][se+i],matrix[se+i][en]);
                swap(matrix[se][se+i],matrix[en][en-i]);
                swap(matrix[se][se+i],matrix[en-i][se]);
            }
            se++;
            en--;
        }
    }
};