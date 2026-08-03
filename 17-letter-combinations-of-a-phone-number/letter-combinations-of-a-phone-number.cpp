class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> ans;
        string path;
        const vector<string> mapping ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        function<void(int)> backtrack = [&](int index){
            if(index==digits.size()){
                ans.push_back(path);
                return;
            }
            for(char c : mapping[digits[index] - '0']){
                path.push_back(c);
                backtrack(index+1);
                path.pop_back();
            }
        };
        backtrack(0);
        return ans;
    }
};