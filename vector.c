#include "vector.h"
#include <stdlib.h>
#include <stdint.h> 

struct _fvec_512 {
    float *elements;
};

/** Inserts VALUE into *VEC at the specified INDEX. */
inline void insert(fvec_512 *vec, uint8_t index, float value) {
    vec->elements[index] = value;
}

/** Returns the value of the element in *VEC at the specified INDEX. */
inline float get(fvec_512 *vec, uint8_t index) {
    return vec->elements[index];
}

/** 
 * Initializes and returns a 512-element-wide floating point vector with the first
 * 512 floats in ELEMENTS.
*/
fvec_512 *init_fvec_512(float *elements) {
    fvec_512 *vec = malloc(512 * sizeof(fvec_512));
    for (int i = 0; i < 512; i += 1) {
        insert(vec, i, elements[i]);
    }
    return vec;
}

/**
 * Frees allocated memory for the 512-element-wide floating-point vector.
*/
void free_fvec_512(fvec_512 *vec) {
    free(vec);
}

/** 
 * Floating-point vector-vector add. Stores result in V3. 
 * Performs v3[i] = v1[i] + v2[i]
*/
void vvfadd(fvec_512 *v1, fvec_512 *v2, fvec_512 *v3) {
    for (int i = 0; i < 512; i += 1) {
        float val = get(v1, i) + get(v2, i);
        insert(v3, i, val);
    }
}

/** 
 * Floating-point vector-vector sub. Stores result in V3. 
 * Performs v3[i] = v1[i] - v2[i]
*/
void vvfsub(fvec_512 *v1, fvec_512 *v2, fvec_512 *v3) {
    for (int i = 0; i < 512; i += 1) {
        float val = get(v1, i) - get(v2, i);
        insert(v3, i, val);
    }
}

/** 
 * Floating-point vector-vector multiply. Stores result in V3. 
 * Performs v3[i] = v1[i] * v2[i]
*/
void vvfmul(fvec_512 *v1, fvec_512 *v2, fvec_512 *v3) {
    for (int i = 0; i < 512; i += 1) {
        float val = get(v1, i) * get(v2, i);
        insert(v3, i, val);
    }
}