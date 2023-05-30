#include "cmplx.h"
#include <math.h>

/** Return complex number constructed via rectangular form. */
complex cmplx_rect(float real, float imag) {
    complex a;
    a.magnitude = sqrt(pow(real, 2) + pow(imag, 2));
    a.argument = atan2(imag, real);
    return a;
}

/** Return a complex number constructed via polar form. */
complex cmplx_polar(float magnitude, float argument) {
    complex a;
    a.magnitude = magnitude;
    a.argument = argument;
    return a;
}

/** Return real component of complex number A. */
float real(complex a) {
    return a.magnitude * cos(a.argument);
}

/** Return imaginary component of complex number A. */
float imag(complex a) {
    return a.magnitude * sin(a.argument);
}

/** Return norm (magnitude) of complex number A. */
float norm(complex a) {
    return a.magnitude;
}

/** Return argument (angle or phase) of complex number A. */
float arg(complex a) {
    return a.argument;
}

/** Return complex conjugate of number A. */
complex conjugate(complex a) {
    complex b;
    b.magnitude = a.magnitude;
    b.argument = -a.argument;
    return b;
}

/**
 * Convert array of N floats to an array of N complex numbers
 * with complex argument = 0.
*/
void convert_arr_float_complex(float *arr, complex *dest, int N) {
    for (int i = 0; i < N; i += 1) {
        dest[i] = cmplx_polar(arr[i], 0);
    }
}

/** 
 * Add two complex numbers and return result. 
 * Compute (a + b)
 */
complex cmplx_add(complex a, complex b) {
    float re = real(a) + real(b);
    float im = imag(a) + imag(b);
    return cmplx_rect(re, im);
}

/** 
 * Subtract two complex numbers and return result. 
 * Compute (a - b)
*/
complex cmplx_sub(complex a, complex b) {
    float re = real(a) - real(b);
    float im = imag(a) - imag(b);
    return cmplx_rect(re, im);
}

/** 
 * Multiply two complex numbers and return result. 
 * Compute (a * b)
*/
complex cmplx_mul(complex a, complex b) {
    complex z;
    z.magnitude = a.magnitude * b.magnitude;
    z.argument = a.argument + b.argument;
    return z;
}

/** 
 * Divide two complex numbers and return result. 
 * Compute (a / b)
*/
complex cmplx_div(complex a, complex b) {
    complex z;
    z.magnitude = a.magnitude / b.magnitude;
    z.argument = a.argument - b.argument;
    return z;
}

/** 
 * Raise complex number A to the Kth power. 
 * Compute (A^k)
*/
complex cmplx_pow(complex a, float k) {
    complex z;
    z.magnitude = pow(a.magnitude, k);
    z.argument = k * a.argument;
    return z;
}

/**
 * Perform (naive) complex matrix-vector multiplication 
 * with dimensions NxN and N.
*/
void cmplx_mvmul(complex **matrix, complex *vector, uint32_t N, complex *dest) {
    /** TODO: optimize matrix multiplication. */
    for (int i = 0; i < N; i += 1) {
        complex *row = matrix[i];
        dest[i] = cmplx_inner_product(row, vector, N);
    }
}

/**
 * Return result of a complex inner product guaranteed to satisfy
 * 1. Additivity
 * 2. Conjugate Symmetry
 * 3. Positive definiteness
 * for two N-length complex vectors.
 * 
 * Implementation of <v, w> := dot product with conjugate of w.
 * TODO: optimize with multithreading / reduction algorithms.
*/
complex cmplx_inner_product(complex *v, complex *w, uint32_t N) {
    complex sum = cmplx_rect(0, 0);
    for (int i = 0; i < N; i += 1) {
        complex inner = cmplx_add(v[i], conjugate(w[i]));
        sum = cmplx_add(sum, inner);
    }
    return sum;
}