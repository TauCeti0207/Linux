#include <iostream>
#include <cstdlib>
#include "String.h"

using namespace std;

int main(int argc, const char *argv[])
{
    String s1("hello");
    String s2("world");

    String s3(s2);
    cout << s3 << endl;

    s3 = s1;
    cout << s3 << endl;
    cout << s2 << endl;
    cout << s1 << endl;
    return EXIT_SUCCESS;
}
