#include <iostream>
#include <string>
#include <chrono>
#include <ratio>


std::string asString(const std::chrono::system_clock::time_point &tp){
    time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = ctime(&t);
    ts.resize(ts.size()-1);
    return ts;
}

int main()
{
    using namespace std;

    typedef chrono::duration<int,ratio<24*3600>> Days;

    chrono::time_point<chrono::system_clock> tp;
    cout << "epoch:     " << asString(tp) << endl;

    tp += Days(1) + chrono::hours(23) + chrono::minutes(55);
    cout << "later:     " << asString(tp) << endl;

    auto diff = tp - chrono::system_clock::time_point();
    cout << "diff:      " << chrono::duration_cast<chrono::minutes>(diff).count() << " minutes" << endl;
    Days days = chrono::duration_cast<Days>(diff);
    cout << "diff       " << days.count() << " day(s)" << endl;

    tp -= chrono::hours(24*365);
    cout << "-1 year:   " << asString(tp) << endl;

    tp -= chrono::duration<int,ratio<3600*24*365>>(100);
    cout << "-100 years:    " << asString(tp) << endl;

    tp -= chrono::duration<int,ratio<3600*24*365>>(100);
    cout << "-100 years:    " << asString(tp) << endl;

    tp -= chrono::duration<int,ratio<3600*24*365>>(100);
    cout << "-100 years:    " << asString(tp) << endl;

    return 0;
}
