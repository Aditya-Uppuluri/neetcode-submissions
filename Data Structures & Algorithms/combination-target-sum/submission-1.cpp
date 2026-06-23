class Solution {
public:
    void helper(vector<int>&nums, vector<vector<int>>&ans, vector<int>temp, int ind, int target) {
        if(ind==nums.size()) {
            if(accumulate(temp.begin(),temp.end(),0)==target) {
                ans.push_back(temp);
            }
            return;
        }
        if(accumulate(temp.begin(),temp.end(),0)>target)
            return;

        //option 1: to pick this number
        temp.push_back(nums[ind]);
        helper(nums,ans,temp,ind,target);
        
        //option 2: to not pick this number
        temp.pop_back();
        helper(nums,ans,temp,ind+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;

        helper(nums,ans,temp,0,target);
        // vector<vector<int>>res(ans.begin(),ans.end());
        return ans;
    }
};
