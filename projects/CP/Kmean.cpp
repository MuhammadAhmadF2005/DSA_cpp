#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class DataPoint
{
private:
    float x, y;

public:
    DataPoint(float x = 0.0, float y = 0.0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float xVal) { x = xVal; }
    void setY(float yVal) { y = yVal; }

    // Operator Overloads
    DataPoint operator+(const DataPoint &other) const
    {
        return DataPoint(x + other.x, y + other.y);
    }

    DataPoint operator-(const DataPoint &other) const
    {
        return DataPoint(x - other.x, y - other.y);
    }

    bool operator==(const DataPoint &other) const
    {
        return x == other.x && y == other.y;
    }

    friend ostream &operator<<(ostream &os, const DataPoint &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

class Cluster
{
private:
    DataPoint centroid;
    DataPoint **points;
    int size;
    int capacity;

public:
    Cluster()
    {
        capacity = 20;
        size = 0;
        points = new DataPoint *[capacity];
    }

    ~Cluster()
    {
        delete[] points;
    }

    void setCentroid(const DataPoint &c)
    {
        centroid = c;
    }

    DataPoint getCentroid() const
    {
        return centroid;
    }

    void addPoint(DataPoint *p)
    {
        if (size < capacity)
        {
            points[size++] = p;
        }
    }

    void clearPoints()
    {
        size = 0;
    }

    void updateCentroid()
    {
        if (size == 0)
            return;
        float sumX = 0, sumY = 0;
        for (int i = 0; i < size; ++i)
        {
            sumX += points[i]->getX();
            sumY += points[i]->getY();
        }
        centroid.setX(sumX / size);
        centroid.setY(sumY / size);
    }

    double computeDistance(const DataPoint &point) const
    {
        float dx = centroid.getX() - point.getX();
        float dy = centroid.getY() - point.getY();
        return sqrt(dx * dx + dy * dy);
    }

    void printCluster(int index) const
    {
        cout << "Cluster " << index + 1 << " (Centroid: " << centroid << "): ";
        for (int i = 0; i < size; ++i)
        {
            cout << *points[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

class KMeans
{
private:
    DataPoint *dataPoints;
    int numPoints;
    Cluster *clusters;
    int K = 3;

public:
    KMeans(DataPoint *points, int numPoints)
    {
        this->numPoints = numPoints;
        dataPoints = points;
        clusters = new Cluster[K];
    }

    ~KMeans()
    {
        delete[] clusters;
    }

    void initializeCentroids()
    {
        srand(time(0));
        for (int i = 0; i < K;)
        {
            int idx = rand() % numPoints;
            bool unique = true;
            for (int j = 0; j < i; ++j)
            {
                if (dataPoints[idx] == clusters[j].getCentroid())
                {
                    unique = false;
                    break;
                }
            }
            if (unique)
            {
                clusters[i].setCentroid(dataPoints[idx]);
                ++i;
            }
        }
        cout << "Initial Centroids:\n";
        for (int i = 0; i < K; ++i)
        {
            cout << "Cluster " << i + 1 << " Centroid: " << clusters[i].getCentroid() << endl;
        }
        cout << endl;
    }

    void assignPointsToClusters()
    {
        for (int i = 0; i < K; ++i)
        {
            clusters[i].clearPoints();
        }

        for (int i = 0; i < numPoints; ++i)
        {
            int nearest = 0;
            double minDist = clusters[0].computeDistance(dataPoints[i]);
            for (int j = 1; j < K; ++j)
            {
                double dist = clusters[j].computeDistance(dataPoints[i]);
                if (dist < minDist)
                {
                    minDist = dist;
                    nearest = j;
                }
            }
            clusters[nearest].addPoint(&dataPoints[i]);
        }
    }

    void updateCentroids()
    {
        for (int i = 0; i < K; ++i)
        {
            clusters[i].updateCentroid();
        }
    }

    void run(int iterations)
    {
        initializeCentroids();
        for (int i = 0; i < iterations; ++i)
        {
            cout << "---- Iteration " << i + 1 << " ----" << endl;
            assignPointsToClusters();
            for (int j = 0; j < K; ++j)
            {
                clusters[j].printCluster(j);
            }
            updateCentroids();
            cout << "Updated Centroids:\n";
            for (int j = 0; j < K; ++j)
            {
                cout << "Cluster " << j + 1 << " Centroid: " << clusters[j].getCentroid() << endl;
            }
            cout << endl;
        }
        printClusters();
    }

    void printClusters()
    {
        cout << "--- Final Clusters After N Iterations ---" << endl;
        for (int i = 0; i < K; ++i)
        {
            clusters[i].printCluster(i);
        }
    }
};

// ---------- MAIN FUNCTION ----------
int main()
{
    const int numPoints = 8;
    DataPoint points[numPoints] = {
        DataPoint(2, 10),
        DataPoint(2, 5),
        DataPoint(8, 4),
        DataPoint(5, 8),
        DataPoint(7, 5),
        DataPoint(6, 4),
        DataPoint(1, 2),
        DataPoint(4, 9)};

    KMeans kmeans(points, numPoints);
    int iterations;
    cout << "Enter number of iterations: ";
    cin >> iterations;
    cout << endl;
    kmeans.run(iterations);

    return 0;
}
