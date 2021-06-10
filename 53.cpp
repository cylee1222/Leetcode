class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<=i; ++j){
                int sum = 0;
                for(int k=j; k<=i; ++k){
                    sum += nums[k];
                }
                if(sum > ans) ans = sum;
            }
        }
        return ans;
    }
};

//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefixSum(nums.size()+1);
        prefixSum[0] = 0;
        for(int i=1; i<nums.size()+1; ++i){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        int ans = nums[0];
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<=i; ++j){
                if(prefixSum[i+1] - prefixSum[j] > ans) ans = prefixSum[i+1] - prefixSum[j];
            }
        }
        return ans;
    }
};

//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        for(int i=2; i<=nums.size()-1; ++i){
            nums[i] += nums[i-1];
        }
        int ans = INT_MIN;
        for(int i=1; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] - nums[j] > ans) ans = nums[i] - nums[j];
            }
        }
        return ans;
    }
};

//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        for(int i=1; i<nums.size(); ++i){
            nums[i] += nums[i-1];
        }
        int ans = INT_MIN;
        int small = nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(nums[i-1] < small) small = nums[i-1];
            if(nums[i] - small > ans) ans = nums[i] - small;
        }
        return ans;
    }
};

//
