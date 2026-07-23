class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int, int>> pairs(n);
        for(int i=0;i<n;++i){
            pairs[i]={nums2[i],nums1[i]};
        }
        sort(pairs.begin(),pairs.end(),[](const auto& a, const auto& b){
            return a.first > b.first;
        });
        priority_queue<int, vector<int>, greater<int>> minheap;
        long long currentsum=0;
        long long maxscore=0;
        for(const auto& [num2, num1]:pairs){
            currentsum+=num1;
            minheap.push(num1);
            if(minheap.size()>k){
                currentsum -= minheap.top();
                minheap.pop();
            }
            if(minheap.size()==k){
                maxscore=max(maxscore,currentsum*(long long)num2);
            }
        }
        return maxscore;
    }
};