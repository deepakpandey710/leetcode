/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function(nums, n) {
    let m = nums.length;
    for (let i = n; i < m; i++) {
        nums[i] = nums[i] * 1024 + nums[i - n];
    }
    let index = 0;
    for (let i = n; i < m; i++, index += 2) {
        nums[index] = nums[i] % 1024;
        nums[index + 1] = Math.floor(nums[i] / 1024);
    }
    return nums;
};