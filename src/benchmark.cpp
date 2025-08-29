#include <iostream>
#include <chrono>
#include <fstream>
#include "power.hpp" 

using namespace std;
using namespace std::chrono;

int main() {
    
    ofstream file("data/timings.csv");
    if (!file) {
        cerr << "Failed to open data/timings.csv for writing\n";
        return 1;
    }

    file << "Function,x,n,time_microseconds\n";

    for (int x = 1; x <= 10; ++x) {
        for (int n = 1; n <= 10; ++n) {
            for (int trial = 0; trial < 10; ++trial) {
                auto start = high_resolution_clock::now();
                naivePower(x, n);
                auto end = high_resolution_clock::now();

                file << "Naive," << x << "," << n << ","
                     << duration_cast<microseconds>(end - start).count() << "\n";

                start = high_resolution_clock::now();
                unoptimizedDCPower(x, n);
                end = high_resolution_clock::now();

                file << "UnoptimizedDC," << x << "," << n << ","
                     << duration_cast<microseconds>(end - start).count() << "\n";

                start = high_resolution_clock::now();
                optimizedDCPower(x, n);
                end = high_resolution_clock::now();

                file << "OptimizedDC," << x << "," << n << ","
                     << duration_cast<microseconds>(end - start).count() << "\n";
            }
        }
    }

    file.close();
    cout << "Timing complete. Results saved to data/timings.csv\n";
    return 0;
}