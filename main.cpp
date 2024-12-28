#include <iostream>
#include "Buffer.h"

using namespace std;

int main()
{
    int x;
    Buffer buf(3, 5);
    buf.escreveChar('a');
    buf.moveCursor(2, 2);
    buf.escreveChar('b');
    buf.moveCursor(3, 2);
    buf.escreveInt(5);
    cout << buf;

    return 0;
}