# 29. Divide Two Integers

> Divide two integers without using multiplication, division and mod operator.

> If it is overflow, return MAX_INT. 

## 思路

* 被除数减去一次除数，结果 + 1
* 被除数减去 2 x 除数，结果 + 2
* 被除数减去 4 x 除数，结果 + 4
*  ......

使用位运算，将除数不断的左移（x2）直到大于被除数

需要注意整数溢出

如输入：

    -2147483648
    1
    -2147483648
    -1

## 实现

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
           // Note: The Solution object is instantiated only once.  
            if (divisor == 1)
                return dividend;
            long long a = abs((double)dividend);  
            long long b = abs((double)divisor);  
            long long res = 0;  
            while(a >= b)  
            {  
                long long c = b;  
                for(int i = 0; a >= c; i++, c <<=1)  
                {  
                    a -= c;  
                    res += 1<<i;  
                }  
            }
            
            if (res == 0x80000000)
                return 2147483647;
            else
                return ((dividend ^ divisor) >> 31) ? (-res) : (res);  
        }  
};
```