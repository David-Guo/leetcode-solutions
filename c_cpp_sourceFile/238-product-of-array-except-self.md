#238. Product of Array Except Self

Given an array of n integers where n > 1, `nums`, return an array `output` such that `output[i]` is equal to the product of all the elements of nums except nums[i].

Solve it **without division** and in O(n).

For example, given `[1,2,3,4]`, return `[24,12,8,6]`.

**Follow up:**
Could you solve it with constant space complexity? (Note: The output array **does not** count as extra space for the purpose of space complexity analysis.)

## 算法思路

两趟遍历数组 `[x1 x2 x3 ... xn]`

第一趟顺序遍历计算 `bi = x1 * x2 * ... * xi-1`

状态转移方程为： `bi = bi-1 * xi-1`

第二趟反序遍历计算 `bi = xi+1 * ... * xn`

状态转移方程为：   `bi-1 = bi * xi`


## My solutions:

```c
#include<stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	int *result = (int *) malloc(sizeof(int) * numsSize);
	
	result[0] = 1;
	int fac_i = 1;
    for (int i = 0; i < numsSize - 1; i++) {
		result[i + 1] = 1;
		fac_i *= nums[i];
		result[i + 1] *= fac_i;
	}

	int inv_fac_i = 1;
	for (int i = numsSize - 1; i > 0; i--) {
		inv_fac_i *= nums[i];
		result[i - 1] *= inv_fac_i;
	}

	return result;
}
```

此题与最大子序列和问题的线性算法非常相像，见我的文章：

[数据结构与算法分析（c 描述）—— 第二章笔记 ](http://blog.csdn.net/u012675539/article/details/50697732)
