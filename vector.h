#ifndef VECTOR_H
#define VECTOR_H
#include <stdint.h>
/** Premature optimization is the root of all evil. Optimize for correctness, then optimize for performance. 
 * TODO: optimize with AVX vector operations.
*/

/** Floating-point vector with 512 elements. */
typedef struct _fvec_512 fvec_512;

/** 
 * Initializes and returns a 512-element-wide floating point vector with the first
 * 512 floats in ELEMENTS. Zero-pad ELEMENTS array as needed.
*/
fvec_512 *init_fvec_512(float elements[]);

/**
 * Frees allocated memory for the 512-element-wide floating-point vector VEC.
*/
void free_fvec_512(fvec_512 *vec);

/** Inserts VALUE into *VEC at the specified INDEX. */
inline void insert(fvec_512 *vec, uint8_t index, float value);

/** Returns the value of the element in *VEC at the specified INDEX. */
inline float get(fvec_512 *vec, uint8_t index);

/** 
 * Floating-point vector-vector add. Stores result in V3. 
 * Performs v3[i] = v1[i] + v2[i]
*/
void vvfadd(fvec_512 *v1, fvec_512 *v2, fvec_512 *v3);

/** 
 * Floating-point vector-vector sub. Stores result in V3. 
 * Performs v3[i] = v1[i] - v2[i]
*/
void vvfsub(fvec_512 *v1, fvec_512 *v2, fvec_512 *v3);

/** 
 * Floating-point vector-vector sub. Stores result in V3. 
 * Performs v3[i] = v1[i] * v2[i]
*/
void vvfmul(fvec_512 *v1, fvec_512 *v2, fvec_512 *v3);

/* TODO: add in vector-float add, vector-float sub, etc. */
#endif