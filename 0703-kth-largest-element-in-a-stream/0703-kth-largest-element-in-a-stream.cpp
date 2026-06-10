class KthLargest {
public:
    priority_queue<int , vector<int>, greater<int>>pm;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto & el : nums){
            pm.push(el);
            if(pm.size()>k){
                pm.pop();
            }
        }
       
    }
    
    int add(int val){
        pm.push(val);

        if(pm.size()>k){
            pm.pop();
        }
        return pm.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */