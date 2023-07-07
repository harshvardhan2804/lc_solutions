//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    int n = price.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy==0){
                        dp[ind][buy][cap]= max(-price[ind]+dp[ind+1][1][cap],0+dp[ind+1][0][cap]);
                    }
                    else{
                        dp[ind][buy][cap]= max(price[ind]+dp[ind+1][0][cap-1],0+dp[ind+1][1][cap]);
                    }
                }
            }
        }

    return dp[0][0][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends