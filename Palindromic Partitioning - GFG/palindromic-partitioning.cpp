//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
bool isPallindrome(int i,int j,string str){
    while(i<j){
        if(str[i++]!=str[j--]) return false;
    }
    return true;
}

int f(int i , string str , int n , vector<int>& dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int minCost = INT_MAX;
    
    for(int j=i;j<n;j++){
        if(isPallindrome(i,j,str)){
            int cost = 1 + f(j+1,str,n,dp);
            minCost = min(minCost,cost);
        }
    }
    return dp[i] = minCost;
}
public:
    int palindromicPartition(string str)
    {
       int n = str.size();
       vector<int>dp(n+1,0);
       dp[n]=0;
       for(int i=n-1;i>=0;i--){
            int minCost = INT_MAX;
            for(int j=i;j<n;j++){
                if(isPallindrome(i,j,str)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost,cost);
                }
            }
            dp[i] = minCost;
       }
       
       return dp[0]-1;
    }
};





//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends