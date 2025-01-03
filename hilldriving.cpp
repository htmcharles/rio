#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    for (int t = 0; t < testcases; t++) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;

        int roads;
        cin >> roads;

        vector<double> slope(roads), distance(roads);
        double total_x = 0, total_y = 0, total_distance = 0;

        for (int i = 0; i < roads; i++) {
            double x, y;
            cin >> x >> y;

            slope[i] = y / x; // Calculate slope
            if (slope[i] >= 0) {
                total_x += x;
                total_y += y;
            }

            // Calculate distance using Pythagoras theorem
            distance[i] = sqrt((x * x )+ (y * y));

            // Add distance only for uphill or flat segments
            if (slope[i] >= 0) {
                total_distance += distance[i];
            }
        }

        // Calculate average slope
        double average_slope = (total_x != 0) ? (total_y / total_x) : 0;

        // Calculate maximum fuel consumption per unit distance
        double max_fuel_per_km = d / total_distance;

        // Calculate velocity for the uphill or flat segments
        double velocity = (max_fuel_per_km - b * average_slope) / a;

        // Ensure velocity is within bounds
        if (velocity > c) velocity = c;
        if (velocity <= 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        // Calculate total time
        double total_time = 0;
        for (int i = 0; i < roads; i++) {
            if (slope[i] < 0) {
                // Downhill segments are traversed at maximum speed
                total_time += distance[i] / c;
            } else {
                // Uphill or flat segments
                total_time += distance[i] / velocity;
            }
            
        cout << total_time << endl;
        }
        cout << slope[0];
    }

    return 0;
}

