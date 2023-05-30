#ifndef CMPLX_H
#define CMPLX_H

/** Represent a complex number with a real and an imaginary component. */
typedef struct _complex complex;

/** Return complex number constructed via rectangular form. */
complex cmplx_rect(float real, float imag);

/** Return complex number constructed via polar form. */
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

#endif