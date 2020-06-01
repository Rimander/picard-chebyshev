#include "matlab.h"
#include <assert.h>
#include <stdlib.h>

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