#include "my_header_only.hpp"
#include <iostream>

using std::cout; using std::endl;

int main()
{
    my::vector<int> vec({1, 2, 3});
    my::vector<int> test = vec;
    int res = test.pop();
    cout << res << endl;
}