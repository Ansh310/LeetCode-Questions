class Solution {
public:
    void genper(vector<int> nums,vector<vector<int>>&v1,int i,int n) {
        if(i==n) {
            v1.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++) {
            swap(nums[i],nums[j]);
            genper(nums,v1,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v1;
        int n=nums.size();
        genper(nums,v1,0,n);
        return v1;
    }
};