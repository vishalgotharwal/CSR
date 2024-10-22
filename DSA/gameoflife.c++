
/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
 

*/

class Solution {
public:
pair <int , int >  findnumber(vector<vector<int>>& board ,int row , int col ,  int startX , int startY ){

     
    
      int countzero = 0 ; 
      int countone = 0 ; 
      vector<int> directionx = {-1 , 1 , 0 , 0 , -1 , -1 , 1 , 1 } ; 
      vector<int>  directiony =  {0 , 0 , -1 , 1 , -1 , 1 , -1 , 1} ; 


     
        

           for(int d = 0 ; d< 8 ; d++){
               int newx = startX + directionx[d];
               int newy = startY + directiony[d] ; 
           
                 if(newx >= 0 && newx < row && newy >=0 && newy < col ){
                    
                      
                      if(board[newx][newy] == 0 ){
                        countzero++;
                      }
                      else{
                        countone++;
                      }
                    
                 }
                

           
          
      }
      return {countzero , countone} ; 
}
    void gameOfLife(vector<vector<int>>& board) {
     
        int row = board.size() ; 
        int col  = board[0].size() ; 
            vector<vector<int>> nextState = board; 

         for(int i = 0 ;i<row ; i++){
             for(int j = 0 ; j<col ; j++){

                auto[countzero , countone] = findnumber(board , row , col , i  , j ) ; 
                 
                if(board[i][j] == 0 ){
                
                      if(countone == 3 ){
                        nextState[i][j] = 1 ; 
                      }

                }
                else{
                    if(countone < 2 ){
                           nextState[i][j] = 0 ; 
                    }
                    else if(countone == 2 || countone == 3 ){
                       nextState[i][j] = 1 ; 
                    }
                    else if(countone > 3){
                           nextState[i][j] = 0 ; 
                    }
                }

             }
         }
         board = nextState ; 
    }
};
