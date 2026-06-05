class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        map<int,int>m;
        for(auto i: nums) {
            m[i]++;
        }
        int ans = 1;
        int curr = 1;
        for(auto i: m) {
            if(m.find(i.first-1)!=m.end()) {
                curr++;
            } else
                curr=1;
            ans=max(ans, curr);
        }
        if(len==0) return 0;
        return ans; 
    }
};

// -1 0 1 3 4 5 6 7 8 9