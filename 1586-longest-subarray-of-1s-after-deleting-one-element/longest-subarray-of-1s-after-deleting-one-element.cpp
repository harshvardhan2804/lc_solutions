class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , ans = 0 , zeroCnt = 0;

        for(int j=0;j<n;j++){
            if(nums[j]==0) zeroCnt++;
            while(zeroCnt>1){
                if(nums[i]==0){
                    zeroCnt--;
                }
                i++;
            }

            ans = max(ans,j-i+1-zeroCnt);
        }
        
        if(ans==n){
            return ans-1;
        }
        return ans;
    }
};