#include "Varparm.h"

namespace Varparm {
    int ivarparm(int count, int first, ...) {

        int result = 1;

        int* pointer = &first;

        for (int i = 0; i < count; i++)
        {
            result *= *(pointer + i);
        }

        return result;
    }


    int svarparm(short count, int first, ...) {

        int max_value = first;

        int* arg_ptr = &first + 1;

        for (int i = 1; i < count; ++i) {

            if (*arg_ptr > max_value) {

                max_value = *arg_ptr;
            }

            arg_ptr++;
        }

        return max_value;
    }

    double fvarparm(float first, ...) {

        double sum = (double)first;
        double* ptr = (double*)(&first + 1);

        if (first == FLT_MAX) { return 0; }

        for (int i = 0; ptr[i] != (double)FLT_MAX; i++) {

            sum += ptr[i];
        }

        return sum;
    }


    double dvarparm(double first, ...) {

        double sum = first;
        double* ptr = &first + 1;

        if (first == DBL_MAX) { return 0; }

        for (int i = 0; ptr[i] != DBL_MAX; i++) {

            sum += ptr[i];

        }
        return sum;
    }
}