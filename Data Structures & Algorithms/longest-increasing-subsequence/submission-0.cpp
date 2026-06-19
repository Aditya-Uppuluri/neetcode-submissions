class Solution {
public:
    int helper(vector<int>&nums, int ind, int prev_ind, vector<vector<int>>&dp) {
        if(ind>=nums.size()) return 0;

        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        //option 1: if it is greater than the prev_ind, add this to the running inc seq
        int op1 = 0, op2 = 0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]) {
            op1 = 1+helper(nums,ind+1,ind,dp);
        }
        //option 2: we can always choose to skip it
        op2 = helper(nums,ind+1,prev_ind,dp);

        return dp[ind][prev_ind+1]=max(op1,op2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len==0 || len==1) return len;
        vector<vector<int>>dp(len, vector<int>(len+1,-1));
        return helper(nums,0,-1,dp);
    }
};
