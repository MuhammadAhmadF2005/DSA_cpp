#include <iostream>
#include <string>

using namespace std;

class Ball
{
private:
    string m_color{"black"};
    float m_radius{10.0};

public:
    Ball()
    {
        print();
    }
    Ball(string color)

        : m_color{color}
    {
        print();
    }
    Ball(float radius)
        : m_radius{radius}
    {
        print();
    }
    Ball(string color, float radius)

        : m_color{color}, m_radius{radius}
    {
        print();
    }

    void print()
    {
        cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main()
{
    Ball def{};
    Ball blue{"blue"};
    Ball twenty{20.0};
    Ball blueTwenty{"blue", 20.0};

    return 0;
}