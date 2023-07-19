#include<bits/stdc++.h>
using namespace std;

class Point {
    public:

    int x;
    int y;
    int distSq;
    int ind;

    Point (int X, int Y, int D, int I): x(X), y(Y), distSq(D), ind(I) {};
};

bool myComparision (Point &p1, Point &p2) {
    return p1.distSq > p2.distSq;
}

int main () {
    
    vector<pair<int, int>> pts = {{3, 3}, {5, -1}, {-2, 4}};

    int k = 2;

    priority_queue<Point, vector<Point>, decltype(&myComparision)> pq(&myComparision);

    for (int i = 0; i < pts.size(); i++) {
        int x = pts[i].first;
        int y = pts[i].second;
        int d = x*x + y*y;
        pq.push(Point(x, y, d, i));
    }
    
    for (int i = 0; i < k; i++) {
        cout << "C" << pq.top().ind << endl;
        pq.pop();
    }

    return 0;
}