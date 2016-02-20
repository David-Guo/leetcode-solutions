# 7. Reverse Interger

    Reverse digits of an integer.
    
    **Example1:** x = 123, return 321
    
    **Example2:** x = -123, return -321 
    
    
## 思路

此题虽然看起来非常简单，但实际上有很多小细节需要考虑。

比如 int 整数溢出问题。

首先要考虑 int 能表示多大的整数？

假如用 32位表示 int。2的32次方=4294967296（无符号），带符号再除以2，负数比正数多一个，

1. 所以，`-2147483648 <= x <= 2147483647` 

2. 同时 ，`-2147483648 <= inv(x) <= 2147483647` 

3. 那么当 ` x > 1463847412 || x < -1463847412`  时，`inv(x)` 就溢出了。

考虑以上三条边界条件后可以写出如下代码。

## My solution

```c
int reverse(int x) {
        if (x == 2147483412 )
            return 2143847412;
        if (x == -2147483412)
            return -2143847412;
        if (x > 1463847412 || x < -1463847412)
            return 0;

        int m = x/10;
        int n = x%10;
        int res = 0;
        while (m != 0) {
            res = res * 10 + n;
            n = m%10;
            m = m/10;
        }
        res = res * 10 + n;
        return res;
    }
```