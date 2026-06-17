class Solution {
public:
    int helper(vector<int>&nums, vector<int>&dp, int idx, int beg_idx, int end_idx) {
        if(end_idx==beg_idx) return nums[end_idx];
        if(idx>end_idx) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int take = nums[idx]+helper(nums,dp,idx+2,beg_idx,end_idx);
        int no_take = helper(nums,dp,idx+1,beg_idx,end_idx);

        return dp[idx]=max(take,no_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int op1 = helper(nums, dp1, 0, 0, n-2);
        int op2 = helper(nums, dp2, 1, 1, n-1);

        return max(op1, op2);
}
};
