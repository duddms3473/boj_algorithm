#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> board(n+1, vector<int>(m+1,1));
    
    for(int i=0;i<puddles.size();i++){
        
        board[puddles[i][1]][puddles[i][0]]=0;
        
        if(puddles[i][0]==1){
            for(int j=puddles[i][1];j<=n;j++){
                board[j][1]=0;
            }
        }
        if(puddles[i][1]==1){
            for(int j=puddles[i][0];j<=m;j++){
                board[1][j]=0;
            }
        }
    }
    
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            if(board[i][j] == 0){
                continue;
            }

            board[i][j] = (board[i-1][j] + board[i][j-1]) % 1000000007;
        }
    }
    
    return board[n][m];
}