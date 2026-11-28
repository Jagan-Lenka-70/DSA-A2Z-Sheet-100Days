class Solution {
public:
    // max subsequence of length k (monotonic stack)
    vector<int> pick(vector<int>& nums, int k) {
        int drop = nums.size() - k;
        vector<int> st;
        for (int x : nums) {
            while (drop > 0 && !st.empty() && st.back() < x) {
                st.pop_back();
                drop--;
            }
            st.push_back(x);
        }
        st.resize(k);
        return st;
    }

    // merge two sequences into the largest one
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        auto i = a.begin(), j = b.begin();
        while (i != a.end() || j != b.end()) {
            // lexicographic compare of remaining suffixes
            if (lexicographical_compare(i, a.end(), j, b.end()))
                res.push_back(*j++);
            else
                res.push_back(*i++);
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;

        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> a = pick(nums1, i);
            vector<int> b = pick(nums2, k - i);
            vector<int> cand = merge(a, b);
            if (best.empty() || cand > best) best = cand;
        }
        return best;
    }
};