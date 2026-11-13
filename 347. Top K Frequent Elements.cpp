class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& p : freq) {
            int number = p.first;
            int frequency = p.second;
            buckets[frequency].push_back(number);
        }

        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int number : buckets[i]) {
                ans.push_back(number);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
