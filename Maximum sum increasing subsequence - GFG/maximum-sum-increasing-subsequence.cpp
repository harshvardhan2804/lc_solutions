//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	   vector<int>dp(n,1),ans(n);
	   for(int i=0;i<n;i++) ans[i] = arr[i];
	   for(int i=0;i<n;i++){
	       for(int prev=0 ; prev<i ; prev++){
	           if(arr[prev] < arr[i] && dp[i]==dp[prev]){
	               dp[i]++;
	               ans[i] = max(ans[i],arr[i]+ans[prev]);
	           }
	       }
	   }
	   
	   return *max_element(ans.begin(),ans.end());
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends