#pragma once
#include <math.h>
#include <stdio.h>
#include "Common.h"

results secant(double a, double b, double (*f)(double), double tolerance, unsigned k)
{
    results secantResults;

    if (!validateInterval(a, b, f))
    {
        fprintf(stderr, "%s", "The values provided will never converge to a root.\n");

        secantResults.steps = 0;
        secantResults.root = 0;

        return secantResults;
    }

	double fRoot = 0, xRoot = 0;
	double fa = f(a);
	double fb = f(b);

	unsigned int steps = 0;

	do
	{
		fa = f(a);
		fb = f(b);
		if (fa == fb)
		{
			printf("The interval has distance zero.");
			break;
		}

		xRoot = b - (b - a) * fb / (fb - fa);
		fRoot = f(xRoot);

		a = b;
		fa = f(b);
		b = xRoot;
		fb = fRoot;

		steps++;

		if (steps > k)
		{
			printf("The results did not converge in %d steps.", k);
			break;
		}

	} while (fabs(fRoot) > tolerance);

    // Results:
    secantResults.steps = steps;
    secantResults.root = xRoot;

    return secantResults;
}