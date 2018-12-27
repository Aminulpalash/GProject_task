class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
          int k = target-nums[i];
          if(mp[k]>0) {  v.push_back(mp[k]-1); v.push_back(i);return v; }
          else mp[nums[i]]=i+1;

         }
    }
};
