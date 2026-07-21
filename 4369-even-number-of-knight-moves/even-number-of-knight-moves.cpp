class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
       if(abs(start[0]-target[0])%2==0){
            if(abs(start[1]-target[1])%2!=0){
                return false;
            }
       }
       if(abs(start[0]-target[0])%2!=0){
            if(abs(start[1]-target[1])%2==0){
                return false;
            }
        }
        return true;
    }
};