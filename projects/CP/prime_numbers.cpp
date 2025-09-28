#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = 0;

        for (int i = 2; i < sqrt(n); i++)
        {

            if (n % i == 0)
            {
                k = 1;
            }
        }

        if (n == 1 || k == 1)
        {
            cout << "no" << endl;
        }
        else
            cout << "Yes" << endl;
    }
}
