//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
         
            int prefix[n], suffix[n];

            prefix[0] = height[0];

            for (int i = 1; i < n; i++) {
                prefix[i] = max(prefix[i - 1], height[i]);
            }

            suffix[n - 1] = height[n - 1];

            for (int i = n - 2; i >= 0; i--) {
                suffix[i] = max(suffix[i + 1], height[i]);
            }
            long long waterTrapped = 0;
            for (int i = 0; i < n; i++) {
                waterTrapped += min(prefix[i], suffix[i]) - height[i];
            }
            return waterTrapped;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends