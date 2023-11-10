
#include <math.h>

bool isprime(int n)
{
    bool flag = true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            flag = false;
        }
    }
    if (n == 1) {
        flag == true;
    }

    return flag;
}