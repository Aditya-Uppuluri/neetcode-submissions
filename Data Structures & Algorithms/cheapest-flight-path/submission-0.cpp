class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0; i<flights.size(); i++) {
            int from = flights[i][0], to = flights[i][1], price = flights[i][2];
            adj[from].push_back({to,price});
        }
        vector<vector<int>>cost(n, vector<int>(k+2,INT_MAX)); //cost[city][no_of_stops]
        cost[src][0]=0; //cost of going to src city with 0 stops = 0;
        // pair<int,pair<int,int>> {price, city, no_of_stops_so_far}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,0}});

        while(!pq.empty()) {
            pair<int,pair<int,int>> curr = pq.top();
            pq.pop();
            int price_to_reach_here = curr.first, curr_city = curr.second.first, num_stops = curr.second.second;
            if(num_stops>k) continue;

            for(auto i: adj[curr_city]) {
                int to_city = i.first, cost_to_city = i.second;
                // if(num_stops + 1 > k) continue;
                if(price_to_reach_here+cost_to_city<cost[to_city][num_stops+1]) {
                    cost[to_city][num_stops+1] = price_to_reach_here+cost_to_city;
                    pq.push({price_to_reach_here+cost_to_city, {to_city, num_stops+1}});
                }
            }
        }
        int cheapest_price = INT_MAX;
        for(int i=0; i<=k+1; i++) {
            cheapest_price = min(cheapest_price,cost[dst][i]);
        }
        if(cheapest_price==INT_MAX) return -1;
        else return cheapest_price;
    }
};
