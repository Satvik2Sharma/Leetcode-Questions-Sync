class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                int current = x;
                int length = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
