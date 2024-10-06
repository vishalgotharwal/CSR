/*
416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/
 class Solution {
public:
  bool solve(vector<int> &nums , int i , int value , vector<vector<int>> &dp   ){
        
 
        //base case 
        if(value == 0){
            return true ; 
        }
        if( i >= nums.size()  || value < 0){ 
          
                return false ; 
            
        }
       if (dp[i][value] != -1) {
            return dp[i][value]; 
        }
       //exclude 
      bool   exclude = solve(nums , i + 1  , value , dp ) ; 

       //include 
       bool  include = false  ; 
       if(nums[i] <= value ){
              include =  solve(nums ,  i + 1  , value - nums[i] , dp) ; 
       }
  dp[i][value] = include || exclude ; 
return dp[i][value] ; 
  }

    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 
        int n = nums.size() ; 
  
    
       for (int num : nums) {
            sum += num; 
        }
         
        if(sum % 2 == 1 ){
            return false ; 
        }
        int value = sum  / 2  ; 
          vector<vector<int>>dp(n  ,vector<int>(value + 1  , -1)) ; 
     
           return  solve(nums   , 0 , value , dp   ) ; 
        
    }
  
};