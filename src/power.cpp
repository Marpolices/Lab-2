#include "power.hpp"


int naivePower(int x, int n) {
    if (n == 0) return 1;
    return x * naivePower(x, n - 1);
}


int unoptimizedDCPower(int x, int n) {
    if (n == 0) return 1;
    int temp = unoptimizedDCPower(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}


int optimizedDCPower(int x, int n) {
    if (n == 0) return 1;
    int temp = optimizedDCPower(x, n / 2);
    int result = temp * temp;
    if (n % 2 == 1)
        result *= x;
    return result;
}
