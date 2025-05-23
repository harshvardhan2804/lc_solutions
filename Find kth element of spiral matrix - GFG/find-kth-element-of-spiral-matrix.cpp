//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int n,int m,int k)
    {
//  		int n = matrix.size();
//         int m = matrix[0].size();
        vector<int>ans;
        int top =0,bottom=n-1,left=0,right=m-1;

        while(top<=bottom && left<=right){
          // from left to right
          for(int i=left;i<=right;i++)
             ans.push_back(matrix[top][i]);
          top++;
          //from top to bottom
          for(int i=top;i<=bottom;i++)
             ans.push_back(matrix[i][right]);
          right--;
          // from right to left
          if(top<=bottom){
             for(int i=right;i>=left;i--)
              ans.push_back(matrix[bottom][i]);
             bottom--;
          }
          // from bottom to top
          if(left<=right){
              for(int i=bottom;i>=top;i--)
                ans.push_back(matrix[i][left]);
              left++;
          }

          
        }
        return ans[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends