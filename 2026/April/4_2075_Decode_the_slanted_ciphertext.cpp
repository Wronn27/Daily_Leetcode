class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        if(rows<=1 || n<1) return encodedText;
        int col=n/rows;

        vector<vector<char>> mat(rows,vector<char>(col,'0'));
        int ind=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                mat[i][j]=encodedText[ind++];
            }
        }
        string ans="";
        for(int j=0;j<col;j++)
        {
            int r=0,c=j;
            while(r<rows && c<col){
                ans+=mat[r++][c++];
            }
        }

        ind=ans.size()-1;
        while(ans[ind]==' ')
        {
            ans.pop_back();
            ind--;
        }

        return ans;
    }
};