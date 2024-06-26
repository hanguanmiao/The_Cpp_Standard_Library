#include <iostream>
#include <forward_list>

int main()
{
    using namespace std;

    forward_list<long> coll = {2,3,5,7,11,13,17};
    coll.resize(9);
    coll.resize(10,99);

    for(auto elem : coll){
        cout << elem << ' ';
    }

    cout << endl;
    return 0;
}
