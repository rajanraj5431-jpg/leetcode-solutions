class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=left.size();
        int r=right.size();
        int mini=n;
        int maxi=0;
        for(int i=0;i<r;i++){
            mini = min(mini,right[i]);
        }
        if(mini==n){
            mini=0;
        }
        else  mini = n-mini;
        for(int i=0;i<l;i++){
            maxi = max(maxi,left[i]);
        }
        maxi=max(maxi,mini);
        return maxi;
    }
};