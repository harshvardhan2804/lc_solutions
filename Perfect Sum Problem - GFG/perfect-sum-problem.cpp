//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 int mod = 1e9 + 7;
    int solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(target == 0)
        {
            return 1%mod;
        }
        if(ind == 0)
        {
            return arr[ind] == target ? 1%mod : 0%mod;
        }
        
        if(dp[ind][target] != -1) return (dp[ind][target])%mod;
        
        int n_pick = solve(ind - 1, target, arr, dp)%mod;
        
        int pick = 0%mod;
        if(arr[ind] <= target)
        {
            pick = solve(ind - 1, target - arr[ind], arr, dp)%mod;
        }
        
        return dp[ind][target] = (pick + n_pick)%mod;
    }
public:
    int perfectSum(int arr[], int n, int sum)
    {
        int zeros = 0%mod;
        vector<int> temp;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 0)
            {
                zeros++;
            }
            else
            {
                temp.push_back(arr[i]);
            }
        }
        vector<vector<int>> dp(n - zeros, vector<int>(sum+1, -1));
        
        int ans = solve(n - zeros - 1, sum, temp, dp)%mod;
        
        return ((ans%mod) * (1<<zeros)%mod)%mod;
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends