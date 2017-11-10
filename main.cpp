#include <iostream>
#include "config/config.h"

#ifdef USE_MYMATH

#include "math/MathFunctions.h"

#endif


using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s num_a num_b \n", argv[0]);
        return 1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
#ifdef USE_MYMATH
    MathFunctions math_functions;
    int           sum = math_functions.TestAdd(a, b);
#else
    int sum = a + b;
#endif
    cout << sum << endl;

    return 0;
}