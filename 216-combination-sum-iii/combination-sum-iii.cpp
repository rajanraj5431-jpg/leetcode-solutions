class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int s=k*(k+1)/2;
        if(n<s){
            return {};
        }
        const vector<int> num = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> backtrack = [&](int index){
            if(path.size()==k){
                int sum=0;
                for(int i=0;i<k;i++){
                    sum+=path[i];
                }
                if(sum==n){
                    ans.push_back(path);
                }
                return;
            }
            for(int i=index;i<9;i++){
                path.push_back(num[i]);
                backtrack(i+1);
                path.pop_back();
            }
        };
        backtrack(0);
        return ans;   
    }
};