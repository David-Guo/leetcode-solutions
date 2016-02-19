# 1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

**Example:**

    Given nums = [2, 7, 11, 15], target = 9,
        
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

My solution: 

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *index = (int *) malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize - 1; i++)
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				index[0] = i + 1;
				index[1] = j + 1;
				return index;
			}
		}
}
```