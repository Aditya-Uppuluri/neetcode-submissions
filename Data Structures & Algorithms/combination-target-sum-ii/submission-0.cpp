class Solution {
public:
    void helper(vector<int>&candidates, set<vector<int>>&ans, vector<int>&temp, int ind, int target) {
        if(accumulate(temp.begin(), temp.end(),0)>target) return;
        if(ind==candidates.size()) {
            if(accumulate(temp.begin(), temp.end(),0)==target) {
                ans.insert(temp);
            }
            return;
        }
        temp.push_back(candidates[ind]);
        helper(candidates,ans,temp,ind+1,target);
        temp.pop_back();

        int curr = ind;
        while(curr<candidates.size() && candidates[curr]==candidates[ind]) {
            curr++;
        }
        helper(candidates,ans,temp,curr,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        set<vector<int>>ans;
        vector<int>temp;

        helper(candidates,ans,temp,0,target);
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};
