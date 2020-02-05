#include <iostream>

using namespace std;



int fib(int n) {
    double Binet = (1 + sqrt(5)) / 2;             // the golden ratio constant
    double mid = pow(Binet, n) / sqrt(5);    // the Binet equation 
    int result = (int)round(mid);                 // round to the closest integer

    return result;
}