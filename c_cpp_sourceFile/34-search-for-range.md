# 34. Search for a Range

    Given a sorted array of integers, find the starting and ending position of a given target value.
    
    Your algorithm's runtime complexity must be in the order of O(log n).
    
    If the target is not found in the array, return [-1, -1].
    
    For example,
    Given [5, 7, 7, 8, 8, 10] and target value 8,
    return [3, 4]. 
    
    
## 思路

二分查找的题，看起来很简单，但我提交了10 才成功，，，需要注意很多细节

可以用下面几个输入提前先测试一下：

* [1,2,3] 1
* [1,2,3] 2
* [1,2,3] 3
* [0, 0, 1, 1,1,4,5,5] 1
* [0, 0, 1, 1,1,4,5,5] 2
* [0,0,0,1,1,1,4,5,5] 0


## 实现

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid, l, r;
        int a[2] = {-1, -1};
        vector<int> res(a, a + 2);
        // 保证 left <= target <= right
        if (target < nums[left] || target > nums[right])
            return res;
        // 一个数
        if (nums.size() == 1) {
            res[0] = 0;
            res[1] = 0;
            return res;
        }
        // 两个数
        if (nums.size() == 2) {
            if (target == nums[left]) {
                res[0] = 0;
                if (target == nums[right])
                    res[1] = 1;
                else
                    res[1] = 0;
            } else { // 与左边不相等
                if (target == nums[right]) {
                    res[0] = 1;
                    res[1] = 1;                   
                }
                return res;
            }
            return res;
        }
        // 保证三个数
        while (left < right) {
            mid = (left + right)/2;
            if (target == nums[mid]) {
                l = r = mid;
                while (target == nums[l] && l >= left)
                    l--;
                while (target == nums[r] && r <= right)
                    r++;
                res[0] = l + 1;
                res[1] = r - 1;
                return res;
            }
            else if(target < nums[mid]) {
                right = mid;
            }
            else {
                if (left == mid) {
                    if (target == nums[right])
                        res[0] = res[1] = right;
                    return res;
                }
                left = mid;
            }

        }
        
        return res;
    }
};
```