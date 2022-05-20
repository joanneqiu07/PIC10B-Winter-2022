//
//  main.cpp
//  final
//
//  Created by Joanne Qiu on 3/16/22.
//

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s1, s2, s3;
    char ch1, ch2, ch3;
    double d1, d2, last4;
    int i1, i2, i3;
    istringstream abc("Phone#: (123)12-1234");
    
    abc >> s1 >> ch1 >> i1 >> ch2 >> i2 >> ch3 >> last4;
    
    cout << s1 << " " << ch1 << i1 << ch2 << i2 << ch3 << last4 << endl;
}
