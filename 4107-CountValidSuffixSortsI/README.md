You are given two integer arrays nums and target, both of length n.

For each index i, consider sorting the suffix nums[i..n - 1] of the original array in non-increasing order.

Return the number of indices i for which the resulting array is equal to target.

A suffix of an array is a subarray that begins at any index and extends to the end of the array.

 
OriginalC++Example 1:


Input: nums = [1,2,3], target = [3,2,1]

Output: 1

Explanation:


	i = 0: The resulting array is [3, 2, 1], which equals target.
	i = 1: The resulting array is [1, 3, 2].
	i = 2: The resulting array is [1, 2, 3].


Only i = 0 is valid, so the answer is 1.


Example 2:


Input: nums = [1,5,6,4,6], target = [1,5,6,6,4]

Output: 2

Explanation:

Choosing either i = 2 or i = 3 results in [1, 5, 6, 6, 4]. No other index produces target. Therefore, the answer is 2.


Example 3:


Input: nums = [7,6,8], target = [8,6,7]

Output: 0

Explanation:

Sorting the suffix starting at indices 0, 1, and 2 produces [8, 7, 6], [7, 8, 6], and [7, 6, 8], respectively. None equals target, so the answer is 0.


 
Constraints:


	1 <= n == nums.length == target.length <= 105
	1 <= nums[i], target[i] <= 10​​​​​​​5​​​​​​​​​​​​​​

