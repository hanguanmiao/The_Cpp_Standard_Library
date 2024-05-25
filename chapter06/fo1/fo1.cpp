#include <iostream>
#include <algorithm>
#include <deque>
#include <functional>
#include "print.hpp"


int main()
{
    using namespace std;

    deque<int> coll = {1,2,3,5,7,11,13,17,19};
    PRINT_ELEMENTS(coll, "initilized:   ");

    transform(coll.cbegin(),coll.cend(), coll.begin(), negate<int>());
    PRINT_ELEMENTS(coll, "negated:      ");

    transform(coll.cbegin(),coll.cend(), coll.cbegin(), coll.begin(), multiplies<int>());
    PRINT_ELEMENTS(coll, "squared:      ");

    return 0;
}
