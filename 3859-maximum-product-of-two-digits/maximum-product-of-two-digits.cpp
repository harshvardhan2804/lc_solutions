class Solution {
public:
    int maxProduct(int n) {
        int ans = 0;
        vector<int>num;
        while(n){
            int x = n%10;
            n /= 10;
            num.push_back(x);
        }
        for(int i=0;i<num.size();++i){
            for(int j=i+1;j<num.size();++j){
                ans = max(ans,num[i]*num[j]);
            }
        }
        return ans;
    }
};