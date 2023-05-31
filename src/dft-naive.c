#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "cmplx.h"
#include "dft-naive.h"

/** 
 * Compute N-point DFT with DFT transformation matrix in O(N^2) time. 
 * Return DFT coefficients in N-length float array.
*/
complex *naive_dft(float *signal, uint32_t N) {
    complex *coeff_matrix = malloc(N * sizeof(complex));
    complex *complex_signal = malloc(N * sizeof(complex));
    complex **dft_matrix = init_dft_matrix(N);
    convert_arr_float_complex(signal, complex_signal, N);
    cmplx_mvmul(dft_matrix, complex_signal, N, coeff_matrix);
    free(complex_signal);
    free_dft_matrix(dft_matrix, N);
    return coeff_matrix;
}

/** 
 * Return normalized N-point DFT unitary transformation matrix.
 * Each element_ij has the form 1/sqrt(N) * omega^ij
 * where omega is the primitive nth root of unity exp(-2pi*i/N)
*/
complex **init_dft_matrix(uint32_t N) {
    complex **matrix = malloc(N * sizeof(complex *));
    for (uint32_t i = 0; i < N; i += 1) {
        complex *row = malloc(N * sizeof(complex));
        for (uint32_t j = 0; j < N; j += 1) {
            complex primitive = nth_root_unity_pow(N, i * j);
            row[j] = cmplx_scale(primitive, 1 / sqrt(N));
        }
        matrix[i] = row;
    }
    return matrix;
}

/** Frees memory allocated to store N-point DFT matrix. */
void free_dft_matrix(complex **dft_matrix, uint32_t N) {
    for (uint32_t i = 0; i < N; i += 1) {
        free(dft_matrix[i]);
    }
    free(dft_matrix);
}
