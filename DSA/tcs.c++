/*
 Output : A
2. One person hands over the list of digits to Mr. String, But Mr. String understands only strings. Within strings also he understands only vowels. Mr. String needs your help to find the total number of pairs which add up to a certain digit D.The rules to calculate digit D are as follow :-
Take all digits and convert them into their textual representation.
Next, sum up the number of vowels i.e. {a, e, i, o, u} from all textual representation.
This sum is digit D
Now, once digit D is known find out all unordered pairs of numbers in input whose sum is equal to D. 
Refer example section for better understanding.
Constraints
1 <= N <= 100
1 <= value of each element in second line of input <= 100
Number 100, if and when it appears in input should be converted to textual representation as hundred and not as one hundred. Hence number of vowels in number 100 should be 2 and not 4


Input
First line contains an integer N which represents number of elements to be processed as input
Second line contains N numbers separated by space
Output
Lower case representation of textual representation of number of pairs in input that sum up to digit D
Note: – (If the count exceeds 100 print “greater 100”)
Examples
Input : 5
1 2 3 4 5
Output : one
Input : 3
7 4 2
Output : zero


*/
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
 int checkPair(int arr[] , int D , int n ){
     int pair = 0 ; 
      for(int i = 0 ; i<n ; i++){
          for(int  j = i+1 ; j<n; j++){
               if(arr[i] + arr[j] == D){
                   pair++;
               }
          }
      }
      return pair ; 
 }

int countVowel(string &textRepresentation){
      int countvowel = 0 ; 
     int size  = textRepresentation.length() ; 
     for(int  i = 0 ; i<size ; i++){
          if(textRepresentation[i] == 'a' || textRepresentation[i] == 'e' || 
           textRepresentation[i] == 'i' || textRepresentation[i] == 'o' ||
           textRepresentation[i] == 'u'
          ){
               countvowel++;
          }
     }
     return countvowel;
}

 int countsum(int arr[] , unordered_map<int , string > &mp , int n  ){
     string textRepresentation  ;
     int countvowel = 0 ; 
 	          for(int i = 0 ; i<n ; i++){
 	          	textRepresentation = mp[arr[i]];
 	          	  
 	          	  countvowel += countVowel(textRepresentation);
 	          	  
			   }
			   cout<<endl ; 
			   
			 
			   
			   return countvowel;
			    
	
 }

int main(){
	 unordered_map<int , string>mp = {
	       {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
        {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
        {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"},
        {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"},
        {19, "nineteen"}, {20, "twenty"}, {30, "thirty"}, {40, "forty"},
        {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"},
        {90, "ninety"}, {100, "hundred"}
	 };
	
	
	 
	   int n ; 
	   int arr[n] ; 
	  cout<<"enter the value of N: ";
	  cin>>n;
	   cout<<"enter the values of N : ";
	   for(int i = 0 ; i<n ; i++){
	   	  cin>>arr[i] ; 
	   }
	   for(int i = 0 ; i<n ; i++){
	   	  cout<<arr[i]<<" " ; 
	   }
	   int D = countsum(arr , mp , n ) ; 
	   cout<<D<<endl;
	   
	   int checkpair = checkPair(arr , D , n ) ;
	   if(checkpair == 0 || checkpair > 100){
	        cout<<"Zero"<<endl ; 
	   }
	   else{
	       
	   
	   cout<<"pair is "<<mp[checkpair]<<endl ; 
	   } 
	   
}