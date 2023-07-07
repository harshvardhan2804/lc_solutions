//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {

        vector<vector<long long>>dp(n+2,vector<long long>(2,0));
                
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                    if(buy==0){
                      profit = max(-prices[ind]+ dp[ind+1][1], 0+dp[ind+1][0]);
                    }

                    else{
                           profit = max(prices[ind]+dp[ind+2][0],0+dp[ind+1][1]);
                    }
                dp[ind][buy]=profit;
            }
        }


        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends