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
