#include <iostream>
#include <vector>
#include <algorithm>
#define ll ll
#define vi vector<int>
#define vll vector<ll>
using namespace std;

struct Edge
{
    int u, v, t, id;
};

/*
void debug_print(int n, const vector<Edge>& edges) {
    for(const auto& e : edges) {
        cout << e.u << " -> " << e.v << " at " << e.t << endl;
    }
}

bool is_valid_D(int t1, int t3, int D) {
    // helper to check D constraint
    return (t3 - t1) <= D;
}
*/

bool compareEdges(const Edge &a, const Edge &b)
{
    return a.t < b.t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, D;
    if (!(cin >> N >> M >> D))
    {
        return 0;
    }

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].t;
        edges[i].id = i;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    vector<vector<Edge>> adjOut(N + 1), adjIn(N + 1);
    for (const auto &e : edges)
    {
        adjOut[e.u].push_back(e);
        adjIn[e.v].push_back(e);
    }

    ll count1 = 0;
    ll count2 = 0;
    ll count3 = 0;

    for (const auto &mid : edges)
    {

        int u = mid.u;
        int v = mid.v;
        int t2 = mid.t;

        for (int i = adjIn[u].size() - 1; i >= 0; --i)
        {
            Edge e1 = adjIn[u][i];
            if (e1.t >= t2)
                continue;
            if (t2 - e1.t > D)
                break;

            int A = e1.u;

            for (const auto &e3 : adjOut[v])
            {
                if (e3.t <= t2)
                {
                    continue;
                }
                if (e3.t - e1.t > D)
                {
                    break;
                }

                if (e3.v == A)
                {
                    count1++;
                }
            }
        }

        for (int i = adjOut[u].size() - 1; i >= 0; --i)
        {
            Edge e1 = adjOut[u][i];
            if (e1.t >= t2)
            {
                continue;
            }
            if (t2 - e1.t > D)
            {
                break;
            }

            int B = e1.v;
            if (B == v)
            {
                continue;
            }

            for (const auto &e3 : adjIn[v])
            {
                if (e3.t <= t2)
                {
                    continue;
                }
                if (e3.t - e1.t > D)
                {
                    break;
                }

                if (e3.u == B)
                {
                    count2++;
                }
            }
        }

        for (int i = adjIn[v].size() - 1; i >= 0; --i)
        {
            Edge e1 = adjIn[v][i];
            if (e1.t >= t2)
            {
                continue;
            }
            if (t2 - e1.t > D)
            {
                break;
            }

            int A = e1.u;
            if (A == u)
            {
                continue;
            }

            for (const auto &e3 : adjOut[v])
            {
                if (e3.t <= t2)
                {
                    continue;
                }

                if (e3.t - e1.t > D)
                {
                    break;
                }

                if (e3.v == A)
                {
                    count3++;
                }
            }
        }
    }

    cout << count1 << " " << count2 << " " << count3 << endl;

    return 0;
}