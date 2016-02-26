题目要求检查括号字符串序列是否匹配

简单的算法是使用一个栈：

    做一个空栈，顺序扫描字符串直到末尾
    如果读到开放符号 “([{” 则入栈
    否则读到 “)]}”，检查栈是否为空，空则报错
    栈不空则检查栈顶元素是否与字符匹配
    扫描结束，检查栈是否为空，不空则报错

cpp 实现代码如下：

```cpp
    bool isValid(string s) {
        stack<char> helpStack;
        size_t i = 0;
        char top;
        while (i != s.size()) {
            if (s[i] != ')' && s[i] != '}' && s[i] != ']')
                helpStack.push(s[i]);
            else {
                if (helpStack.size() == 0)
                    return false;
                top = helpStack.top();
                switch(s[i]) {
                    case ')':
                        if(top == '(')
                            helpStack.pop();
                        else
                            return false;
                        break;

                    case '}':
                        if(top == '{')
                            helpStack.pop();
                        else
                            return false;
                        break;

                    case ']':
                        if(top == '[')
                            helpStack.pop();
                        else
                            return false;
                        break;
                }
            }
            i++;
        }
        if (helpStack.size() == 0)
            return true;
        else
            return false;
    }

```