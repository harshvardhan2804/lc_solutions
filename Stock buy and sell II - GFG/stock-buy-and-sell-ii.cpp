//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            int profit;
            for(int buy = 0 ; buy <=1 ; buy++ ){
               if(buy==0){
                   profit = max(-prices[ind] + dp[ind+1][1] , 0 + dp[ind+1][0]);
               } 
               else{
                   profit = max(prices[ind] + dp[ind+1][0] , 0 + dp[ind+1][1]);  
               }
               dp[ind][buy] = profit;
            }
        }
        
        return dp[0][0];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends