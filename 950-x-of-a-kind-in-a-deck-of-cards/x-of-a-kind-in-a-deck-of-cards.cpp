class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int>mp;  //{val,occ}
        for(auto d : deck){
           mp[d]++;
        }
        int res = 0;
        for(auto it: mp){
          res = __gcd(it.second,res);
        }
        return res > 1;
    }
};