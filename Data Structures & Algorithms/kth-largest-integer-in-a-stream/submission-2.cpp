class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    vector<int>int_stream;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->int_stream = nums;

        for(int i=0; i<int_stream.size(); i++) { //push all of them in the min heap
            pq.push(int_stream[i]);
        }
    }
    int add(int val) {
        // if(pq.size()<k) {
            pq.push(val);
        // }
        if(pq.size()==k) {
            return pq.top(); 
        }
        else if(pq.size()>k){
            while(!pq.empty() && pq.size()>k) { //prune it everytime there are more than k
                pq.pop();
            }
            return pq.top();
        }
    }
};
