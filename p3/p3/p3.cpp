// p3.cpp : Defines the entry point for the application.
//

#include "p3.h"

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

class KinematicSolver {
public:
    double l1;
    double l2;

    KinematicSolver(double p_l1, double p_l2)
    {
        l1 = p_l1;
        l2 = p_l2;
    }

    double* Solve(double x, double y) {
        double* result = new double[2];
        double alpha = acos(x / sqrt(x * x + y * y)) - acos(l1 * l1 - l2 * l2 + (x * x + y * y) / (2 * sqrt(x * x + y * y) * l1));
        double beta = M_PI - acos(l1 * l1 - l2 * l2 + (x * x + y * y) / (2 * sqrt(x * x + y * y) * l1));
        result[0] = alpha;
        result[1] = beta;
        return result;
    }
};

int main() {
    KinematicSolver A(1.1, 2.1);
    std::cout << A.Solve(6, 5)[0] << " " << A.Solve(4, 5)[1] << std::endl;
    return 0;
}
