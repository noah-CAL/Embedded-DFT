#include <stdint.h>
#include "cmplx.h"

/** 
 * Compute N-point DFT with DFT transformation matrix in O(N^2) time. 
 * Return DFT coefficients in N-length float array.
*/
complex *naive_dft(float *signal, uint32_t N);

/** 
 * Return normalized N-point DFT transformation matrix.
*/
complex **init_dft_matrix(uint32_t N);

/** Frees memory allocated to store N-point DFT matrix. */
void free_dft_matrix(complex **dft_matrix, uint32_t N);