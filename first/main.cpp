#include <iostream>
#include "bird.h"

using namespace std;

int main() {
    Bird b;
    b.SetName("我是老鹰\n");
    cout << b.Name();
    return 0;
};