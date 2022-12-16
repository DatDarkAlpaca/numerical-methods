#include "root_finding/bisection.h"
#include "root_finding/newton.h"

double function(double x)
{
	return (x * x) - 2;
}

double derivative(double x)
{
	return 2 * (x);
}

int main()
{
	// Bisection Method:
#if 0
	results bisectionResults = bisection(1.0, 2.0, function, TOLERANCE);
	printResults(&bisectionResults);
#endif

	// Newton's Method:
#if 1
	results newtonResults = newton(1., function, derivative, TOLERANCE);
	printResults(&newtonResults);
#endif

	return 0;
}