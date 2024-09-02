class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        long long sum = 0;
        int n = chalk.size();
        vector<long long> pref(n);
        for (int i = 0; i < n; i++) {
            sum += chalk[i];
            pref[i] = chalk[i];
            if (i)pref[i] += pref[i - 1];
        }
        int rem = k % sum;
        long long l = 0, r = n - 1;
        int ans = 0;
        while (l <= r) {
            int md = (l + r) >> 1;
            if (pref[md] > rem) {
                ans = md;
                r = md - 1;
            } else l = md + 1;
        }
        return ans;
    }
};
