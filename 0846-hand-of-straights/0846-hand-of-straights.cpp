class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(hand.size() % groupSize != 0)return false;
        unordered_map<int , int>freq;
        for(auto& el : hand){
            freq[el]++;   
        }

        vector<int>nodup;
        for(auto& pair: freq){
            nodup.push_back(pair.first);
        }
        sort(nodup.begin() , nodup.end());

        for(int h: nodup){
            if(freq[h] > 0){
               int startcount = freq[h];
                for(int i = h ; i<h+groupSize ; i++){
                    if(freq[i] < startcount){
                        return false;
                    }
                    freq[i] -= startcount;
                }

            }
        }
        return true;
    }
};