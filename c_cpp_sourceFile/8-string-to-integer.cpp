#include<iostream>
#include<string>
using namespace std;

int myAtoi(string str) {
    int m = 0;
    int flag = 1;

    std::size_t found = str.find_first_not_of(' ');
    //cout << "found is: " << found << endl;
    if(str[found] == '-' || str[found] == '+') {
        if (str[found] == '-')
            flag = -1;
        found++;
    }

    for(size_t i = found; i < str.size(); i++) {
        if(str[i] >='0' && str[i] <= '9') {
            if (m > 214748364) {
                if(flag == 1)
                    return 2147483647;
                else return -2147483648;
            }
            if (m == 214748364) {
                if (flag == 1 && str[i] - '0' > 7)
                    return 2147483647;
                if (flag == -1 && str[i] - '0' > 8)
                    return -2147483648;
            }
            m = m * 10 + str[i] - 48;
        }
        else {
            if (m == 0)
                return 0;
            else if(m != 0) {
                if (flag == -1)
                    return -m;
                return m;
            }
        }

    }
    if (flag == -1)
        return -m;
    return m;
}

int main() {
    cout << "result : " << myAtoi("    -114321")  << endl;
    cout << "result : " << myAtoi("    -114321aaaa")  << endl;
    cout << "result : " << myAtoi("  -  114321aaaa")  << endl;
    cout << "result : " << myAtoi(" asf 123341asdf")  << endl;
    cout << "result : " << myAtoi("+1") << endl;
    cout << "result : " << myAtoi("-004152aaaa111") << endl;
    cout << "-2147483648 : " << myAtoi("-2147483648") << endl;
    cout << "-2147483649 : " << myAtoi("-2147483649") << endl;
    cout << "2147483647 : " << myAtoi("2147483647") << endl;
    cout << "2147483648 : " << myAtoi("2147483648") << endl;
    cout << "      -11919730356x : " << myAtoi("      -11919730356x") << endl; 
    return 0;
}
