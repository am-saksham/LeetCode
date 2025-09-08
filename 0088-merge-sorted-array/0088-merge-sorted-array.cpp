class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m+n;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        while(nums1.size() > total) {
            auto it = find(nums1.begin(), nums1.end(), 0);
            if(it != nums1.end()) {
                nums1.erase(it);
            }
        }
        for(int x : nums1) {
            cout << x << " ";
        }
        cout << "\n";
    }
};