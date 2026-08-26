class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        set <int> freq;
        int n1=nums1.size();
        int n2=nums2.size();
        int n1min=10;
        for(int i=0;i<n1;i++){
            freq.insert(nums1[i]);
            n1min=min(n1min,nums1[i]);
        }
        int mini=100;
        int n2min=10;
        for(int i=0;i<n2;i++){
            if(freq.contains(nums2[i])){
                mini=min(mini,nums2[i]);}
            n2min=min(n2min,nums2[i]);
            
        }
        if(n1min>n2min){
            mini=min(mini,n2min*10+n1min);
        }
        else{
            mini=min(mini,n1min*10+n2min);
        }
        return mini;
    }
};