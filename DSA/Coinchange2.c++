/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

class Solution {
public: 
int solve(int amount ,vector<int> &coins , int index  , vector<vector<int>> &dp){
      //base case 
      int count = 0 ; 
       if(amount ==  0 ){
          return 1 ; 
       }
     if(amount < 0 || index < 0){
        return 0 ; 
     }
    if(dp[index][amount]!= -1){
        return dp[index][amount] ; 
    }
      //exclude 
            int exclude = solve(amount , coins , index - 1 , dp ) ; 

      //include 
      int include = 0 ; 
      
         
             include = solve(amount - coins[index], coins , index ,dp   );
 
     dp[index][amount] = include+exclude ;   
             return  dp[index][amount] ; 

   

}
    int change(int amount, vector<int>& coins) {
         int index = coins.size() ; 
         vector<vector<int>>dp(index , vector<int>(amount + 1 , -1 )); 
       return   solve(amount , coins , index-1  , dp );
      
    }
};