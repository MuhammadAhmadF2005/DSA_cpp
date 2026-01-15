#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        double total = 0.0;
        double low = 1e18, high = -1e18;

        for (auto &sq : squares)
        {
            double y = sq[1];
            double side = sq[2];

            total += side * side;
            low = min(low, y);
            high = max(high, y + side);
        }

        double target = total / 2.0;

        // binary search//
        for (int i = 0; i < 60; i++)
        {
            double mid = (low + high) / 2.0;

            if (areaBelow(mid, squares) < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
    // Computes total area of square portions below y = h
    double areaBelow(double h, vector<vector<int>> &squares)
    {
        double area = 0.0;

        for (auto &sq : squares)
        {
            double y = sq[1];
            double side = sq[2];

            if (h <= y)
            {
                // Entire square above line
                continue;
            }
            else if (h >= y + side)
            {
                // Entire square below line
                area += side * side;
            }
            else
            {
                // Line cuts the square
                area += side * (h - y);
            }
        }

        return area;
    }
};