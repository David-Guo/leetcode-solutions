# 6. ZigZag Conversion

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility) 

    P   A   H   N
    A P L S I I G
    Y   I   R

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);

`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`. 

## 解决思路

Zigzag:即循环对角线结构

两次循环，依次将字符串从原字符串 s 复制到字符数组 res 中

向下循环: nRows

斜角线循环: nRows-2 (减去首尾两个端点)

## My solution

```cpp
#include<iostream>
#include<string>

using namespace std;

string convert(string s, int nRows){
    if(nRows == 1) return s;
    string res[nRows];
    int i = 0, j, gap = nRows-2;
    while(i < s.size()){
        for(j = 0; i < s.size() && j < nRows; ++j) res[j] += s[i++];
        for(j = gap; i < s.size() && j > 0; --j) res[j] += s[i++];
    }
    string str = "";
    for(i = 0; i < nRows; ++i)
        str += res[i];
    return str;
}

int main() {
    string s = "PAYPALISHIRING";
    cout << "result is: " << convert(s, 4) << endl;
}
```
