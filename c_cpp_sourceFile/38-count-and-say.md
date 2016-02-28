# 38. Count and Say

> The count-and-say sequence is the sequence of integers beginning as follows:
> 1, 11, 21, 1211, 111221, ...

> 1 is read off as "one 1" or 11.
> 11 is read off as "two 1s" or 21.
> 21 is read off as "one 2, then one 1" or 1211.

> Given an integer n, generate the nth sequence.

## 思路

最外遍历`n` ，内层循环遍历字符串，遍历字符串时需要对重复出现的字符进行计数。

可以采用递归实现或非递归实现。

非递归实现如下：

## 实现

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        string str = "1";
        int i, pre, count;
        if (n <= 1)
            return res;
        while(n - 1> 0) {
            i = 0;
            res = "";
            count = 0;
            // Count and Say
            pre = i;
            while (true) {
                while(str[pre] == str[i]) {
                    count++;
                    i++;
                }
                // str[pre] != str[i-1]
                res += to_string(count);
                res += str[pre];
                pre = i;
                count = 0;
                // 循环结束条件
                if (i >= str.size()) {
                    break;
                }
            }

            //
            str = res;
            n--;
        }
        return res;
    }
};
```