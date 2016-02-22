#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    string s = to_string(x);
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
        if (s[i++] != s[j--])
            return false;

    return true;
}

int main () {
    cout << isPalindrome(-12344321) << endl;
    cout << isPalindrome(-214783548) << endl;
}
