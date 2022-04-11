#include <iostream>
#include "RightAngled.hpp"

using namespace std;

int main() {
    Triangle t1(0, 0, 0);
    Triangle t2(t1);
    Triangle t3 = t2;
    cout << "a++" << endl;
    t3++;
    cout << t3.get_a() << endl;
    cout << "a--" << endl;
    t3--;
    cout << t3.get_a() << endl;
    ++t3;
    cout << "++c" << endl;
    cout << t3.get_c() << endl;
    --t3;
    cout << "--c" << endl;
    cout << t3.get_c() << endl;
    
    RightAngled rightangled1;
    Read(rightangled1);
    RightAngled rightangled2(rightangled1);
    Display(rightangled2);
    return 0;
}

