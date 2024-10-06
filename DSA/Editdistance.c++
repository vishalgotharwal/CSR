/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

*/

class Solution {
public:
 int solve(string &word1 , string &word2 , int index1 , int index2 , vector<vector<int>> &dp) {
       
    //base case
       if(word1.length() == index1){
          return word2.length() - index2 ; 
       }
          if(word2.length() == index2){
          return word1.length() - index1 ; 
       }

       if(dp[index1][index2] != -1){ 
            return dp[index1][index2]  ;
       }
        
             int ansreal = 0 ; 
       if(word1[index1] == word2[index2]){ 
             return  solve(word1 , word2 , index1+1 , index2+1 , dp ) ; 
       }
       else{
           //insert 
          int valueinsert = 1 +  solve(word1, word2 , index1 , index2+ 1  , dp );

          //delete

          int valuedelete = 1+  solve(word1, word2 , index1 + 1  , index2  , dp );

               
          //replace

          int valuereplace = 1+ solve(word1, word2 , index1+1 , index2+ 1 , dp );

          
    dp[index1][index2 ] =   min({valueinsert , valuedelete ,valuereplace} ); 

   return   dp[index1][index2 ] ; 
  
       }


 }

    int minDistance(string word1, string word2 ) {
        int i = word1.length() ; 
        int j = word2.length() ; 
        vector<vector<int>>dp( i , vector<int>( j +1 , -1 )); 
       return  solve(word1 , word2  , 0 , 0 , dp) ; 
    }
};