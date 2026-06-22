class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq; //max heap
        for(int i=0; i<points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            int dist = x*x + y*y;
            if(pq.size()==k) {
                if(dist<pq.top().first) {
                    pq.pop();
                    pq.push({dist,{x,y}});
                }
                else continue;
            }
            else
                pq.push({dist,{x,y}});
        }
        set<vector<int>>ans;
        while(!pq.empty()) {
            pair<int,pair<int,int>>curr = pq.top();
            pq.pop();
            vector<int>temp;
            temp.push_back(curr.second.first);
            temp.push_back(curr.second.second);
            ans.insert(temp);
        }
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};
