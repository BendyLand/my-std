#include "mystl.hpp"
#include <iostream>

using std::cout; using std::endl;

int main()
{
    my::vector<int> vec({1, 2, 3});
    my::vector<int> test = vec;
    std::vector<int> test2 = vec;
    int res = test.pop();
    cout << res << endl;

    my::string str = "this is a test";
    my::vector<my::string> parts = str.split(" ");
    cout << parts;
    std::string newstr = parts.join("~");
    cout << newstr << endl;
}