#include <iostream>
using namespace std;

class Demo
{
    int a, b;

public:
    Demo() // default constructor
    {
        int a = 5;
        int b = 10;
        cout << "Default Constructor " << a + b << endl;
    }
    Demo(int a, int b) : a(a), b(b) // parameterised constructor
    {
        cout << "parameterized constructor -values" << a << " " << b << endl;
    }

} instance;

int main()
{

    return 0;
}
