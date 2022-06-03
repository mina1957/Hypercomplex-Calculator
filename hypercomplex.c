#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "hypercomplex.h"


// Construct a hypercomplex number a+b*u from the given coordinates.
// Argument u2 gives the value of u*u.
// The effect of operations on numbers with different values of u2
// is undefined.



struct h hPack(double a, double b, double u2)
{

    struct h my_pack = {a, b, u2};

    return my_pack;
}


// Return the coordinates of a hypercomplex number
// through the given pointers.
void hUnpack(struct h z, double *a, double *b)
{
    *a = z.a;
    *b = z.b;

}

// Return z1 + z2.
struct h hAdd(struct h z1, struct h z2)
{
    double sum_real = z1.a + z2.a;
    double sum_image = z1.b + z2.b;
    double u_sqr = z1.u2;

    return hPack(sum_real, sum_image, u_sqr);
}

// Return z1 - z2.
struct h hSubtract(struct h z1, struct h z2)
{
    double dif_real = z1.a - z2.a;
    double dif_image = z1.b - z2.b;
    double u_sqr = z1.u2;

    return hPack(dif_real, dif_image, u_sqr);
}

// Return z1 * z2.
struct h hMultiply(struct h z1, struct h z2)
{
    double prod_real = (z1.u2 * z1.b * z2.b) + (z1.a * z2.a);
    double prod_image = (z1.b * z2.a) +  (z1.a * z2.b);
    double u_sqr = z1.u2;

    return hPack(prod_real, prod_image, u_sqr);
}

// Given z == a + b*u, return its conjugate a - b*u.
struct h hConjugate(struct h z)
{
    double a_loc = z.a;
    double b_loc = z.b * (-1);
    double u_sqr = z.u2;

    return hPack(a_loc, b_loc, u_sqr);
    
}

// Return q such that q*z2 == z1.
// If z2 is a zero divisor, behavior is undefined.
struct h hDivide(struct h z1, struct h z2)
{
    double denom = (hMultiply (z2, hConjugate(z2))).a;
    struct h numerator = hMultiply (z1, hConjugate(z2));
    double a_loc = numerator.a/denom;
    double b_loc = numerator.b/denom;
    double u_sqr = z1.u2;

    return hPack(a_loc, b_loc, u_sqr);
}
