#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    cout << setprecision(10) << fixed;
    for (int t = 0; t < testCases; t++) {
        double centerX1, centerY1, radius1;
        double centerX2, centerY2, radius2;
        cin >> centerX1 >> centerY1 >> radius1;
        cin >> centerX2 >> centerY2 >> radius2;
        double distance = sqrt((centerX1 - centerX2) * (centerX1 - centerX2) + (centerY1 - centerY2) * (centerY1 - centerY2));
        if (centerX1 == centerX2 && centerY1 == centerY2 && radius1 == radius2) {
            cout << -1 << endl;
        } else if (distance > abs(radius1 + radius2) || distance < abs(radius1 - radius2)) {
            cout << 0 << endl;
        } else {
            double a = (radius1 * radius1 - radius2 * radius2 + distance * distance) / (2 * distance);
            double height = sqrt(radius1 * radius1 - a * a);
            if (height < 0.0000001) {
                cout << 1 << endl;
                double intersectX = centerX1 + a * (centerX2 - centerX1) / distance;
                double intersectY = centerY1 + a * (centerY2 - centerY1) / distance;
                cout << intersectX << ' ' << intersectY << endl;
            } else {
                cout << 2 << endl;
                double intersectX = centerX1 + a * (centerX2 - centerX1) / distance;
                double intersectY = centerY1 + a * (centerY2 - centerY1) / distance;

                double intersectX1 = intersectX + height * (centerY2 - centerY1) / distance;
                double intersectX2 = intersectX - height * (centerY2 - centerY1) / distance;
                double intersectY1 = intersectY - height * (centerX2 - centerX1) / distance;
                double intersectY2 = intersectY + height * (centerX2 - centerX1) / distance;

                vector<vector<double>> points = {{intersectX1, intersectY1},
                                                 {intersectX2, intersectY2}};
                sort(points.begin(), points.end());
                cout << points[0][0] << ' ' << points[0][1] << endl;
                cout << points[1][0] << ' ' << points[1][1] << endl;
            }

        }
        cout << endl;
    }
    return 0;
}
