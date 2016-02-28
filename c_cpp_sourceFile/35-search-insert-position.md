# 35. Search Insert Position

> Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

> You may assume no duplicates in the array.

> Here are few examples.

    [1,3,5,6], 5 → 2
    [1,3,5,6], 2 → 1
    [1,3,5,6], 7 → 4
    [1,3,5,6], 0 → 0 
    
## 思路

类似上题，使用二分查找，

* 若 `target` 在 `mid` 处返回 `mid` ，
* 若小与 `mid` 则将 `mid` 赋给 `right`
* 若大于 `mid` 需要进行一次判断 `left == mid` 再将 `mid` 赋给 `left`

进行 `left == mid` 判断的原因是，求平均数得到 `mid` 的过程会舍弃末尾的小数

## 实现

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        // 保证 left < target < right
        if (target > nums[right])
            return right + 1;
        if (target <= nums[left])
            return left;
        
        while (left < right) {
            if (target == nums[right])
                return right;
            if (target == nums[left])
                return left;
            mid = (right + left)/2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                right = mid;
            else { // target > left
                if (left == mid)
                    return left + 1;
                left = mid;
            }

        }
        
    }
};
```