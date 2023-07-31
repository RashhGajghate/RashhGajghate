#include<stdio.h>
#include<math.h>


float evaluate_polynomial(float x, float coeff[], int degree)  //Function for evaluating polynomial
{
    float result = 0.0;
    int i;
    // Evaluate the polynomial
    for (i = 0; i <= degree; i++)
        result += coeff[i] * pow(x, i);
    return result;
}

int main()
{
    float coeff[] = {2.0, 1.0, 4.0}; // Array of coefficients
    int degree = 2; // Degree of the polynomial
    float x = 3.0; // Value of x

    // Evaluate the polynomial for the given value of x
    float result = evaluate_polynomial(x, coeff, degree);

    // Output
    printf("The value of the polynomial for x = %f is %f\n", x, result);

}
