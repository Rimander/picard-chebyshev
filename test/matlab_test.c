#include "matlab.h"
#include <assert.h>

int fliplr_test() {
    double *a, *b;
    createarray(3, &a);
    createarray(3, &b);

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    fliplr(3, a, &b);

    assert(b[2] == a[0]);
    assert(b[1] == a[1]);
    assert(b[0] == a[2]);

    freearray(a);
    freearray(b);
    return 0;
}


int repmat_test() {
    double **a, **b;
    creatematrix(2, 2, &a);
    creatematrix(4, 4, &b);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    repmat(2, 2, a, 2, 2, &b);

    assert(a[0][0] == b[0][0]);
    assert(a[0][1] == b[0][1]);
    assert(a[0][0] == b[0][2]);
    assert(a[0][1] == b[0][3]);
    assert(a[1][0] == b[1][0]);
    assert(a[1][1] == b[1][1]);
    assert(a[1][0] == b[1][2]);
    assert(a[1][1] == b[1][3]);
    assert(a[0][0] == b[2][0]);
    assert(a[0][1] == b[2][1]);
    assert(a[0][0] == b[2][2]);
    assert(a[0][1] == b[2][3]);
    assert(a[1][0] == b[3][0]);
    assert(a[1][1] == b[3][1]);
    assert(a[1][0] == b[3][2]);
    assert(a[1][1] == b[3][3]);

    return 0;
}


int column_test() {
    double **a, *b;
    creatematrix(2, 2, &a);
    createarray(2, &b);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    column(2, 1, a, &b);

    assert(a[0][1] == b[0]);
    assert(a[1][1] == b[1]);

    return 0;
}


int productarray_test() {
    double *a, *b;
    createarray(2, &a);
    createarray(2, &b);
    a[0] = 1;
    a[1] = 2;
    b[0] = 3;
    b[1] = 4;

    double result = productarray(2, a, b);

    assert(result == 11);
    return 0;
}


int summatrix_test() {
    double **a, *b;
    creatematrix(2, 2, &a);
    createarray(2, &b);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    summatrix(2, 2, a, &b);
    assert(b[0] == 4);
    assert(b[1] == 6);
    return 0;
}


int sum_test() {
    double **a, **b, **c;
    creatematrix(2, 2, &a);
    creatematrix(2, 2, &b);
    creatematrix(2, 2, &c);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    b[0][0] = 1;
    b[0][1] = 2;
    b[1][0] = 3;
    b[1][1] = 4;
    sum(2, 2, a, b, &c);
    assert(c[0][0] == 2);
    assert(c[0][1] == 4);
    assert(c[1][0] == 6);
    assert(c[1][1] == 8);
    return 0;
}


int mult_test() {
    double **a, **b, **c;
    creatematrix(2, 2, &a);
    creatematrix(2, 2, &b);
    creatematrix(2, 2, &c);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    b[0][0] = 1;
    b[0][1] = 2;
    b[1][0] = 3;
    b[1][1] = 4;
    mult(2, 2, 2, 2, a, b, &c);
    assert(c[0][0] == 7);
    assert(c[0][1] == 10);
    assert(c[1][0] == 15);
    assert(c[1][1] == 22);
    return 0;
}


int cross_test() {
    double **a, **b, **c;
    creatematrix(3, 2, &a);
    creatematrix(3, 2, &b);
    creatematrix(3, 2, &c);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    a[2][0] = 3;
    a[2][1] = 4;
    b[0][0] = 1;
    b[0][1] = 2;
    b[1][0] = 3;
    b[1][1] = 4;
    b[2][0] = 3;
    b[2][1] = 4;
    cross(3, 2, a, b, &c);
    assert(c[0][0] == 0);
    assert(c[0][1] == 0);
    assert(c[1][0] == 6);
    assert(c[1][1] == 8);
    assert(c[2][0] == -6);
    assert(c[2][1] == -8);
    return 1;
}


int sign_test() {
    assert(sign(2) == 1);
    assert(sign(0) == 0);
    assert(sign(-5) == -1);
    return 0;
}


int times_test() {
    double *a, **b, **c;
    createarray(2, &a);
    creatematrix(2, 2, &b);
    creatematrix(2, 2, &c);
    a[0] = 1;
    a[1] = 2;
    b[0][0] = 1;
    b[0][1] = 2;
    b[1][0] = 3;
    b[1][1] = 4;
    times(2, 2, a, b, &c);
    assert(c[0][0] == 1);
    assert(c[0][1] == 4);
    assert(c[1][0] == 3);
    assert(c[1][1] == 8);
    return 0;
}
