#ifndef CMPLX_H
#define CMPLX_H
#include <stdint.h>

/** Represent a complex number with a real and an imaginary component. */
typedef struct _complex complex;

/** 
 * Return complex number constructed via rectangular form. 
 * Z = real + i * imag
 */
complex cmplx_rect(float real, float imag);

/** 
 * Return complex number constructed via polar form. 
 * Z = magnitude * exp(i * argument)
 * */
complex cmplx_polar(float magnitude, float argument);

/** Return real component of complex number A. */
float real(complex a);

/** Return imaginary component of complex number A. */
float imag(complex a);

/** Return norm (magnitude) of complex number A. */
float norm(complex a);

/** Return argument (angle or phase) of complex number A. */
float arg(complex a);

/** Return complex conjugate of number A. */
complex conjugate(complex a);

/**
 * Convert array of N floats to an array of N complex numbers
 * with complex argument = 0.
*/
void convert_arr_float_complex(float *arr, complex *dest, int N);

/** 
 * Add two complex numbers and return result. 
 * Compute (a + b)
 */
complex cmplx_add(complex a, complex b);

/** 
 * Subtract two complex numbers and return result. 
 * Compute (a - b)
*/
complex cmplx_sub(complex a, complex b);

/** 
 * Multiply two complex numbers and return result. 
 * Compute (a * b)
*/
complex cmplx_mul(complex a, complex b);

/** 
 * Divide two complex numbers and return result. 
 * Compute (a / b)
*/
complex cmplx_div(complex a, complex b);

/** 
 * Raise complex number A to the Kth power. 
 * Compute (A^k)
*/
complex cmplx_pow(complex a, float k);

/**
 * Scale complex number A by the constant N.
*/
complex cmplx_scale(complex a, float n);

/**
 * Return Nth root of unity.
 * Z = exp(-2 * pi * i / N)
*/
complex nth_root_unity(int n);

/**
 * Return Nth root of unity raised to a power.
 * omega = nth_root_unity(n)
 * Z = omega^k
*/
complex nth_root_unity_pow(int n, int k);

/**
 * Perform complex matrix-vector multiplication 
 * with dimensions NxN and N and returning the
 * norm of each resulting element.
*/
void cmplx_norm_mvmul(complex **matrix, complex *vector, uint32_t N, complex *dest);

/** We will primarily be focusing on multiplying complex numbers as opposed to adding...(?)
 * So optimizing for complex multiplication will be best.
*/
struct _complex {
    float magnitude;
    float argument;
};


#endif