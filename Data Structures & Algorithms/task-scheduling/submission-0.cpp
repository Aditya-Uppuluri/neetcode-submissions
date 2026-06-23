class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //queue -> should contain the next ready task
        //pq -> should contain the next most frequently occuring task
        unordered_map<char,int>m;
        for(auto i: tasks) m[i]++;

        queue<pair<int,int>>q; //{next available time, cnt}
        priority_queue<int>pq;
        for(auto i: m) pq.push(i.second);

        int time=0;
        while(!pq.empty() || !q.empty()) {
            time++;
            if(pq.empty()) { //there are no more tasks to be done
                pair<int,int>curr = q.front();
                int next_time = curr.first, remaining = curr.second;
                time = next_time;
            }
            else { //if there are tasks to be done
                int remaining = pq.top();
                pq.pop();
                if(remaining>1)
                    q.push({time+n,remaining-1});
            }
            if(!q.empty() && time==q.front().first) {
                pq.push(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};
