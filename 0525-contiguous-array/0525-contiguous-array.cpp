class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixIndex;
        prefixIndex[0] = -1;

        int maxLength = 0, prefixSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                prefixSum += -1;
            } else {
                prefixSum += 1;
            }

            if(prefixIndex.find(prefixSum) != prefixIndex.end()) {
                maxLength = max(maxLength, i-prefixIndex[prefixSum]);
            } else {
                prefixIndex[prefixSum] = i;
            }
        }
        return maxLength;
    }
};