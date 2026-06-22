// Last updated: 6/22/2026, 4:29:44 PM
1class Solution {
2public:
3  bool check(int x, int y, vector<vector<char>>& board, char ch) {
4    
5        for (int t = 0; t < 9; t++) {
6            if (board[x][t] == ch) return false;
7        }
8        
9      
10        for (int t = 0; t < 9; t++) {
11            if (board[t][y] == ch) return false;
12        }
13        
14        
15        int boxRowStart = (x / 3) * 3;
16        int boxColStart = (y / 3) * 3;
17        for (int i = 0; i < 3; i++) {
18            for (int j = 0; j < 3; j++) {
19                if (board[boxRowStart + i][boxColStart + j] == ch) return false;
20            }
21        }
22        
23        return true;
24    }
25    bool solve(vector<vector<char>>& board , int i , int j){
26                if(i==9){
27                    return true;
28                }
29                if(j==9){
30                   return solve(board,i+1,0);
31                    
32                }
33
34            if(board[i][j]!='.') return solve(board ,i,j+1);
35
36            for(int k= 1;k<=9;k++){
37                   char ch = '0' + k;
38                     if(check(i,j,board,ch)){
39                       board[i][j] = ch;
40                       if(solve(board,i,j+1)) return true;
41                        board[i][j] = '.';
42                     }
43            }   
44            return false;     
45    }
46    void solveSudoku(vector<vector<char>>& board) {
47        
48               solve(board,0,0);
49
50            
51    }
52};