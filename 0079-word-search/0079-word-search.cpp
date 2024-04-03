class Solution {
public:
    vector<int>dir={-1,0,1,0,-1};
    bool f(int i, int j,int k,vector<vector<char>>& board, string &word){
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[k]){
            return false;
        }
        if(k==word.size()-1)return true;
        bool ans=false;
        for(int l=0;l<4;l++){
            int x=i+dir[l], y=j+dir[l+1];
            char temp=board[i][j];
            board[i][j]='.';
            ans|=f(x,y,k+1,board,word);
            board[i][j]=temp;
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(f(i,j,0,board,word))return true;
            }
        }
        return false;
    }
};