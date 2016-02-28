## 实现 c 函数 strstr() 

> Implement strStr().

> Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 

返回子字符串在原字符串中第一次匹配的位置，否则放回 -1

实现还是比较简单的就是需要注意一些细节


## 思路

* 检查输入
* 遍历原字符串
* 记忆与子串第一个字符匹配的位置，设置两个指针分别向后移
* 检查循环结束条件，作出相应的返回

值得注意的是，在两个指针分别后移动过程中，开始我是向下面这样写的：

```cpp
while(haystack[i] && needle[i] && haystack[i++] == needle[j++])
    ;
if (j == needle.size())
    return match;
i = match;
```

这样对下面的输入 [input] 会报错：

	"mississippi"
	"issip"

**原因主要在于如果 `while` 是由 `haystack[i] != needle[j]` 结束的话，`i， j` 都会向后移动依次，如果下文需要 `i， j` 用于判断，则容易出错。**

## 实现


```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        if(haystack == "")
            return -1;
        size_t j = 0;
        size_t match, i;
        for(i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]) {
                j = 1;
                match = i;
                i++;
                while(haystack[i] && needle[j] && haystack[i] == needle[j]) {
                    i++;
                    j++;
                }
                if (j == needle.size())
                    return match;
                else if(i == haystack.size())
                    return -1;
                i = match;
            }
        }
        if (j != haystack.size())
            return -1;
        
    }
};
```
