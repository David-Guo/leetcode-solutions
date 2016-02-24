#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    size_t size = strs.size();
    string res;
    string res = "";
    if (size == 0)
        return res;
    if (size == 1)
        return strs[0];
    size_t i, j, min = strs[0].size();
    for(i = 1; i < size; i++) {
        if (strs[i].size() < min)
            min = strs[i].size();
    }
    while (true) {
        char c;
        for (j = 0; j < min; j++) {
            for (i = 1; i < size; i++) {
                c = strs[0][j];
                if (c != strs[i][j])
                    return res;
            }
            res += c;
        }
        return res;
    }
}

int main() {
    vector<string> strs;
    strs.push_back("asd");
    strs.push_back("asdjf");
    strs.push_back("asdg");
    cout << "result is: " << longestCommonPrefix(strs) << endl;
    return 0;
}
