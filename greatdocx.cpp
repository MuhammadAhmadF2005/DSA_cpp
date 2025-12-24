#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   GLOBAL UTILITIES
   ========================================================= */

#define nl "\n"

/* =========================================================
   ===================== AVL TREE ==========================
   ========================================================= */

struct Node
{
    int val;
    Node *llink;
    Node *rlink;
    int height;

    Node(int x)
    {
        val = x;
        llink = rlink = nullptr;
        height = 1;
    }
};

class AVLTree
{
    Node *root = nullptr;

    int height(Node *p)
    {
        return p ? p->height : 0;
    }

    int bf(Node *p)
    {
        return p ? height(p->llink) - height(p->rlink) : 0;
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->llink;
        Node *T = x->rlink;

        x->rlink = y;
        y->llink = T;

        y->height = max(height(y->llink), height(y->rlink)) + 1;
        x->height = max(height(x->llink), height(x->rlink)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->rlink;
        Node *T = y->llink;

        y->llink = x;
        x->rlink = T;

        x->height = max(height(x->llink), height(x->rlink)) + 1;
        y->height = max(height(y->llink), height(y->rlink)) + 1;

        return y;
    }

    Node *insert(Node *p, int key)
    {
        if (!p)
            return new Node(key);

        if (key < p->val)
            p->llink = insert(p->llink, key);
        else if (key > p->val)
            p->rlink = insert(p->rlink, key);
        else
            return p;

        p->height = 1 + max(height(p->llink), height(p->rlink));
        int balance = bf(p);

        if (balance > 1 && key < p->llink->val)
            return rightRotate(p);
        if (balance < -1 && key > p->rlink->val)
            return leftRotate(p);
        if (balance > 1 && key > p->llink->val)
        {
            p->llink = leftRotate(p->llink);
            return rightRotate(p);
        }
        if (balance < -1 && key < p->rlink->val)
        {
            p->rlink = rightRotate(p->rlink);
            return leftRotate(p);
        }

        return p;
    }

    void inorder(Node *p)
    {
        if (!p)
            return;
        inorder(p->llink);
        cout << p->val << " ";
        inorder(p->rlink);
    }

public:
    void insert(int x) { root = insert(root, x); }
    void display()
    {
        inorder(root);
        cout << nl;
    }
};

/* =========================================================
   ===================== BST ===============================
   ========================================================= */

class BST
{
    Node *root = nullptr;

    Node *insert(Node *p, int x)
    {
        if (!p)
            return new Node(x);
        if (x < p->val)
            p->llink = insert(p->llink, x);
        else if (x > p->val)
            p->rlink = insert(p->rlink, x);
        return p;
    }

    void inorder(Node *p)
    {
        if (!p)
            return;
        inorder(p->llink);
        cout << p->val << " ";
        inorder(p->rlink);
    }

public:
    void insert(int x) { root = insert(root, x); }
    void display()
    {
        inorder(root);
        cout << nl;
    }
};

/* =========================================================
   ===================== GRAPH =============================
   ========================================================= */

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, bool directed = false)
    {
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u])
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
        }
        cout << nl;
    }

    void DFSUtil(int u, vector<bool> &visited)
    {
        visited[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            if (!visited[v])
                DFSUtil(v, visited);
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << nl;
    }

    /* -------- Cycle Detection (Undirected) -------- */
    bool cycleUtil(int u, int parent, vector<bool> &visited)
    {
        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                if (cycleUtil(v, u, visited))
                    return true;
            }
            else if (v != parent)
                return true;
        }
        return false;
    }

    bool hasCycleUndirected()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
            if (!visited[i] && cycleUtil(i, -1, visited))
                return true;
        return false;
    }

    /* -------- Topological Sort (DAG) -------- */
    void topoDFS(int u, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;
        for (int v : adj[u])
            if (!visited[v])
                topoDFS(v, visited, st);
        st.push(u);
    }

    void topologicalSort()
    {
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
            if (!visited[i])
                topoDFS(i, visited, st);

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << nl;
    }
};

/* =========================================================
   ===================== HASHING ===========================
   ========================================================= */

/* -------- OPEN ADDRESSING -------- */

class HashOpen
{
    vector<int> table;
    int size;
    const int EMPTY = -1;
    const int DELETED = -2;

public:
    HashOpen(int s)
    {
        size = s;
        table.assign(size, EMPTY);
    }

    int hash(int key) { return key % size; }

    void insertLinear(int key)
    {
        int h = hash(key);
        for (int i = 0; i < size; i++)
        {
            int idx = (h + i) % size;
            if (table[idx] == EMPTY || table[idx] == DELETED)
            {
                table[idx] = key;
                return;
            }
        }
    }

    void insertQuadratic(int key)
    {
        int h = hash(key);
        for (int i = 0; i < size; i++)
        {
            int idx = (h + i * i) % size;
            if (table[idx] == EMPTY || table[idx] == DELETED)
            {
                table[idx] = key;
                return;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << i << " -> " << table[i] << nl;
    }
};

/* =========================================================
   ===================== SORTING ===========================
   ========================================================= */

void quickSort(int A[], int low, int high)
{
    if (low >= high)
        return;

    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (A[j] <= pivot)
            swap(A[++i], A[j]);

    swap(A[i + 1], A[high]);
    int pi = i + 1;

    quickSort(A, low, pi - 1);
    quickSort(A, pi + 1, high);
}

void merge(int A[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        A[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}

/* =========================================================
   ===================== EXAMPLE MAINS =====================
   ========================================================= */

/*
int main()
{
    AVLTree t;
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.display(); // Balanced AVL
}
*/

/*
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.BFS(0);
    g.DFS(0);
    cout << g.hasCycleUndirected();
}
*/

/*
int main()
{
    HashOpen h(7);
    h.insertLinear(10);
    h.insertLinear(17);
    h.insertQuadratic(24);
    h.display();
}
*/

/*
int main()
{
    int A[] = {5,4,3,2,1};
    quickSort(A,0,4);
    for(int x:A) cout<<x<<" ";
}
*/
