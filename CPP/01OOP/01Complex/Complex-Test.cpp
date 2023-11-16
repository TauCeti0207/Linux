//
//  main.cpp
//  Complex
//

#include <cstdlib>
#include "Complex.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Complex c1(2, 1);
    Complex c2(4, 0);

    cout << c1 << endl;
    cout << c2 << endl;

    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 / 2 << endl;
    cout << (c2 - 2) << endl;
    cout << (5 + c2) << endl;

    cout << conj(c1) << endl;
    cout << norm(c1) << endl;
    cout << polar(10, 4) << endl;

    cout << (c1 += c2) << endl;
    cout << (c1 -= c2) << endl;
    cout << (c1 *= c2) << endl;
    cout << (c1 /= c2) << endl;

    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;
    cout << (c1 == 2) << endl;
    cout << (c2 != 4) << endl;

    cout << +c2 << endl;
    cout << -c2 << endl;

    return EXIT_SUCCESS;
}
