#include "vec.h"

int main()
{
    myVector v;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        cout << v;
    }

    // Copy
    myVector cp{v};
    cout << endl;
    cout << cp << endl;


    myVector w{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << w << endl;

    w.push_back(11);
    cout << w << endl;
    cout << w.operator[](1) << endl;

    return 0;
}
