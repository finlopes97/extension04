#include <stdio.h>
#include <stdint.h>

void matrix_sum(int16_t *matrix_a, uint8_t *dimensions_of_a, int16_t *matrix_b, int16_t *result_matrix);
void matrix_add(int16_t *matrix_a, uint8_t *dimensions_of_a, uint8_t scalar, int16_t *result_matrix);
void matrix_scale(int16_t *matrix_a, uint8_t *dimensions_of_a, uint8_t mult_scalar, int16_t *result_matrix);
