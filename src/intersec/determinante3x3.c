#include <miniRT.h>

float determinante(float **matrix) {
    float det = 0;
    det += matrix[0][0] * (matrix[1][1]*matrix[2][2] - matrix[2][1]*matrix[1][2]);
    det -= matrix[0][1] * (matrix[1][0]*matrix[2][2] - matrix[2][0]*matrix[1][2]);
    det += matrix[0][2] * (matrix[1][0]*matrix[2][1] - matrix[2][0]*matrix[1][1]);
    return det;
}
