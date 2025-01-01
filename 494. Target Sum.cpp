class Solution {
    int cnt = 0;

    int trace(int i, int sum, List<Integer> nums, int target) {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }
        return trace(i + 1, sum + nums.get(i), nums, target) + trace(i + 1, sum - nums.get(i), nums, target);
    }

    int findTargetSumWays(List<Integer> nums, int target) {
        return trace(0, 0, nums, target);
    }
}


