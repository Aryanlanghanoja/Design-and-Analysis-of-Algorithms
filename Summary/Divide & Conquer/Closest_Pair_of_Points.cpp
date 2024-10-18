#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    int x, y;
};

int compareX(const void* a, const void* b) {
    Point* p1 = (Point*)a, * p2 = (Point*)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) {
    Point* p1 = (Point*)a, * p2 = (Point*)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(Point P[], int n, pair<Point, Point>& closest_pair) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min) {
                min = dist(P[i], P[j]);
                closest_pair = { P[i], P[j] };
            }
    return min;
}

float min(float x, float y) {
    return (x < y) ? x : y;
}

float stripClosest(Point strip[], int size, float d, pair<Point, Point>& closest_pair) {
    float min = d;
    qsort(strip, size, sizeof(Point), compareY);
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min) {
                min = dist(strip[i], strip[j]);
                closest_pair = { strip[i], strip[j] };
            }
    return min;
}

float closestUtil(Point P[], int n, pair<Point, Point>& closest_pair) {
    if (n <= 3)
        return bruteForce(P, n, closest_pair);

    int mid = n / 2;
    Point midPoint = P[mid];

    pair<Point, Point> left_pair, right_pair;
    float dl = closestUtil(P, mid, left_pair);
    float dr = closestUtil(P + mid, n - mid, right_pair);

    float d = min(dl, dr);
    closest_pair = (dl < dr) ? left_pair : right_pair;

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    float strip_dist = stripClosest(strip, j, d, closest_pair);
    if (strip_dist < d)
        d = strip_dist;

    return d;
}

float closest(Point P[], int n, pair<Point, Point>& closest_pair) {
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n, closest_pair);
}

int main() {
    Point P[] = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    int n = sizeof(P) / sizeof(P[0]);

    pair<Point, Point> closest_pair;
    float min_distance = closest(P, n, closest_pair);

    cout << "The smallest distance is " << min_distance << endl;
    cout << "The points are: (" << closest_pair.first.x << ", " << closest_pair.first.y
        << ") and (" << closest_pair.second.x << ", " << closest_pair.second.y << ")" << endl;

    return 0;
}
