// Two-dimensional hypercomplex numbers.
//
// Each number is of the form a + b*u, where
// u*u == a for some real number a.
//
// Examples:
//
// If u*u == -1, we get the complex numbers.
// If u*u == 0, we get the dual numbers.
// If u*u == 1, we get the split numbers.
//
// Since we can't compute with reals, we will represent
// coordinates as doubles.

// User is politely requested not to access fields
// of this struct directly; use hPack and hUnpack.
struct h
{
    double a;
    double b;
    double u2;
};

// Constructs a hypercomplex number a+b*u from the given coordinates.
// Argument u2 gives the value of u*u.
// The effect of operations on numbers with different values of u2
// is undefined.
struct h hPack(double a, double b, double u2);

// Returns the coordinates of a hypercomplex number
// through the given pointers.
void hUnpack(struct h z, double *a, double *b);

// Returns z1 + z2.
struct h hAdd(struct h z1, struct h z2);

// Returns z1 - z2.
struct h hSubtract(struct h z1, struct h z2);

// Returns z1 * z2.
struct h hMultiply(struct h z1, struct h z2);

// Given z == a + b*u, returns its conjugate a - b*u.
struct h hConjugate(struct h z);

// Returns q such that q*z2 == z1.
// If z2 is a zero divisor, behavior is undefined.
struct h hDivide(struct h z1, struct h z2);
