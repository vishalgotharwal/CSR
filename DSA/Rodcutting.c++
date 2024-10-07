/*
Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: Consider 1-based indexing.

Example:

Input: n = 8, price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.

*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int solve(int price[] , int  n , int index , vector<vector<int>>&dp ){
       //base case 
       if(n == 0 ){
            return 0;
       }
       if(index >= n ){
           return 0 ; 
       }
       if(dp[n][index] != -1){
           return dp[n][index];
       }
       
                 //add vale
                 int include = 0 ; 
                 if(n >= index+1)
    include =  price[index] + solve(price , n-(index+1) ,0 , dp);
       
       
       
       //remove
       
       int exclude =  solve(price , n , index+1  ,dp ); 
          dp[n][index] =max(include , exclude) ; 
       return dp[n][index];
  }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1 , vector<int>(n , -1)); 
      return   solve(price , n , 0  , dp) ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
