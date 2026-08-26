class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int l=0;
        int r=skill.size()-1;
        int sum=skill[0]+skill[r];
        while(l<r){
            if(sum!=skill[l]+skill[r]) return -1;
            l++;
            r--;
        }
        l=0;
        r=skill.size()-1;
        long long ans=0;
        while(l<r){
            ans+=(long long)(skill[l]*skill[r]);
            l++;
            r--;
        }
        return ans;
    }
};