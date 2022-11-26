class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0; i<n; i++){
            map<int,int>mp;
            for(int j =0; j<n; j++){
                if(isdigit(board[i][j])) {
                    mp[board[i][j]]++;
                    if(mp[board[i][j]]==2) return false;
                }
            }
            mp.clear();
            for(int j =0; j<n; j++){
                if(isdigit(board[j][i])) {
                    mp[board[j][i]]++;
                    if(mp[board[j][i]]==2) return false;
                }
            }
        }
        for(int i=0; i<n; i+=3){
            for(int j =0; j<n; j+=3){
                map<int,int> mp;
                for(int k = i; k<i+3; k++){
                    for(int l = j; l<j+3; l++){
                         if(isdigit(board[k][l])) {
                            mp[board[k][l]]++;
                            if(mp[board[k][l]]==2) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
