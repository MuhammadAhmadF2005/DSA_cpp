#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a1, a2, a3, b1, b2, b3;
        cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
        static const int size = 3;
        int arr_a[size] = {a1, a2, a3};
        sort(arr_a, arr_a + size);
        int score_1 = arr_a[1] + arr_a[2];

        int arr_b[size] = {b1, b2, b3};
        sort(arr_b, arr_b + size);
        int score_2 = arr_b[1] + arr_b[2];

        if (score_1 > score_2)
        {
            cout << "Alice" << endl;
        }

        else if (score_2 > score_1)
        {
            cout << "bob" << endl;
        }
        else
        {
            cout << "tie" << endl;
        }
    }
}
