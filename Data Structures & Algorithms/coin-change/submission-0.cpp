class Solution {
public:
    int helper(vector<int>&coins, int amount, int idx) {
        if(idx==coins.size()-1) {
            if(amount%coins[idx]==0) 
                return amount/coins[idx];
            else return 1e9;
        }
        if(amount<0 || idx>=coins.size())  
            return 1e9;

        //option1
        int take = 1e9;
        if(amount>=coins[idx]) 
            take = 1+helper(coins,amount-coins[idx],idx);
        //option2
        int skip = helper(coins,amount,idx+1);

        return min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        //base cases
        if(coins.size()==0) return -1;
        int ans = helper(coins,amount,0);
        if(ans>=1e9) return -1; else return ans;
    }
};
