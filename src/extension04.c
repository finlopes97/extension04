// Ex E4.0
// 
// Matrix arithmetic operations are commonly required in many
// algorithms. In this exercise you are required to write four 
// functions which will implement some common matrix operations.
//
// Specifically:
//     matrix_sum()   - Matrix addition, A+B
//     matrix_add()   - Add a scalar to a matrix A+k
//     matrix_scale() - Scale (multiply) a matrix by a scalar, A*k
//     matrix_mul()   - Matrix multiplication, A*B
//
// A matrix of dimensions m x n has m rows and n columns, so we can
// represent one in C as a 2-dimensional array of the form matrix[m][n].
// 
// Example. Consider a matrix A of dimension 2 x 2, and a matrix B 
// of dimension 2 x 3:
//
// A = 
// | 1 2 |
// | 3 4 |
//
// B =
// | 1 2 3 |
// | 4 5 6 |
//
// In matrix addition we take element-by element sums, e.g.:
//
// B+B = 
// | 1 2 3 | + | 1 2 3 | = | 1+1 2+2 3+3 | = | 2  4  6 |
// | 4 5 6 |   | 4 5 6 |   | 4+4 5+5 6+6 |   | 8 10 12 |
//
// The two input matricies must have the same dimension and
// the result will be of the same dimension.
//
// In matrix-scalar addition we add a scalar to every element, 
// e.g.:
//
// B+1 = 
// | 1 2 3 | + 1 = | 1+1 2+1 3+1 | = | 2  3  4 |
// | 4 5 6 |       | 4+1 5+1 6+1 |   | 5  6  7 |
//
// The result will be of the same dimension as the input.
//
// To scale a matrix, we multiply every element by a scalar, 
// e.g.:
//
// B*2 = 
// | 1 2 3 | * 2 = | 1*2 2*2 3*2 | = | 2  4  6 |
// | 4 5 6 |       | 4*2 5*2 6*2 |   | 8 10 12 |
//
// The result will be of the same dimension as the input.
//
// In matrix multiplication we take the dot-product of the rows
// of the LHS matrix with the columns of the RHS matrix. The dot-
// product is an element by element multiplication. e.g.:
//
// A*B = 
// [ 1 2 ] * [ 1 2 3 ] = [ (1*1 + 1*4)  (1*2 + 2*5)  (1*3 + 2*6) ] = [  9 12 15 ]  
// [ 3 4 ]   [ 4 5 6 ]   [ (3*1 + 4*4)  (3*2 + 4*5)  (3*3 + 4*6) ]   [ 19 26 33 ]
//
// 0 * 0 - 0 * 1 - 0 * 2 
//
// The inner dimensions of the matricies must be the same and the
// result will be a matrix of dimension equal to the outer dimensions. 
// e.g. the result of matrix multiplication of an m x n matrix and n x p matrix 
// will be an m x p matrix.
//
// You can find lots of resources on-line which define these operations in detail, 
// e.g. https://online.stat.psu.edu/statprogram/reviews/matrix-algebra/arithmetic
//
// A matrix shall be represented as a 2-dimensional array of 16-bit
// signed integers. When passing a matrix as an argument to a function,
// a pointer to the first element of the array should be used. As matricies
// can have different dimensions, when passing a matrix as an argument you
// must also pass the pointer to a two-element 8-bit unsigned integer array 
// containing the number of rows in the first element and number of columns 
// in the second element. Scalars shall be passed as a 16-bit signed integer.
// it is not necessary to pass the dimension of the result matrix as this is
// fully defined by the dimension of the input operands.
// 
// The order of arguments for your functions shall be as follows:
// 
// matrix_sum()   - matrix A, dimension of A, matrix B, result matrix
// matrix_add()   - matrix A, dimension of A, scalar addend, result matrix
// matrix_scale() - matrix A, dimension of A, scalar multiplicand, result matrix
// matrix_mul()   - matrix A, dimension of A, matrix B, dimension of B, result matrix
//
// You must define prototypes for your functions in extension06.h so that these
// may be called by external code. The implementation of your functions should be
// in extension06.c.
//
// You can write code to test your functions in main.c. We've provided some example
// code to call the functions you write, and print matricies via the serial interface.
// main.c will be replaced by our own test code when we test your functions.

#include <stdio.h>
#include <stdint.h>

void matrix_sum(int16_t *matrix_a, uint8_t *dimensions_of_a, int16_t *matrix_b, int16_t *result_matrix) {
    for (uint8_t i = 0; i < dimensions_of_a[0]; i++) {
        for (uint8_t j = 0; j < dimensions_of_a[1]; j++) {
            result_matrix[i*dimensions_of_a[1]+j] = matrix_a[i*dimensions_of_a[1]+j] + matrix_b[i*dimensions_of_a[1]+j];
        }
    }
}

void matrix_add(int16_t *matrix_a, uint8_t *dimensions_of_a, int16_t scalar, int16_t *result_matrix) {
    for (uint8_t i = 0; i < dimensions_of_a[0]; i++) {
        for (uint8_t j = 0; j < dimensions_of_a[1]; j++) {
            result_matrix[i*dimensions_of_a[1]+j] = matrix_a[i*dimensions_of_a[1]+j] + scalar;
        }
    }
}

void matrix_scale(int16_t *matrix_a, uint8_t *dimensions_of_a, int16_t mult_scalar, int16_t *result_matrix) {
    for (uint8_t i = 0; i < dimensions_of_a[0]; i++) {
        for (uint8_t j = 0; j < dimensions_of_a[1]; j++) {
            result_matrix[i*dimensions_of_a[1]+j] = matrix_a[i*dimensions_of_a[1]+j] * mult_scalar;
        }
    }
}

void matrix_mul(int16_t *matrix_a, uint8_t *dimensions_of_a, int16_t *matrix_b, uint8_t *dimensions_of_b, int16_t *result_matrix) {

    // Give everyone a letter, letters make everyone feel better
    uint8_t m, n, p, q, i, j, k;

    // Columns in first matrix need to be equal to rows in second matrix
    // Tuples are in order of rows, cols

    m = dimensions_of_a[0]; // Rows of matrix a
    n = dimensions_of_a[1]; // Columns of matrix a
    p = dimensions_of_b[0]; // Rows of matrix b
    q = dimensions_of_b[1]; // Columns of matrix b

    // Check to make sure we can actually math this shit
    if (n != p) {
        printf("Error has occured, matrices cannot be multiplied if the rows of the first matrice are not equal to the columns of the second.\nYou can (not) math this shit.");
        return;
    }

    for (i = 0; i < m; i++) { // For every row of matrix a ->
        for (j = 0; j < q; j++) { // For every column of matrix b ->
            result_matrix[i*q+j] = 0; // Clear existing values at address ij of result matrix
            for (k = 0; k < p; k++) { // For every row in matrix b - >
                result_matrix[i*q+j] += matrix_a[i*n+k] * matrix_b[k*p+j];
            }
        }
    }
}
// Write your code for Ex E4.0 above this line.
