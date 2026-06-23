class Solution {
public:
    void helper(vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans, int ind) {
        if(ind==nums.size()) {
            ans.push_back(temp);
            return;
        }
        //option 1: either choose to take in this element
        temp.push_back(nums[ind]);
        helper(nums,temp,ans,ind+1);

        //option 2: choose to not take in this element
        temp.pop_back();
        helper(nums,temp,ans,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;

        helper(nums,temp,ans,0);

        return ans;
    }
};
