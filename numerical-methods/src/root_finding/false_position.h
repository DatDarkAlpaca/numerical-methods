#pragma once
#include <math.h>
#include <stdio.h>
#include "Common.h"

results falsePosition(double a, double b, double (*f)(double), double tolerance, unsigned k)
{
	results falsePositionResults;

	if (!validateInterval(a, b, f))
	{
		fprintf(stderr, "%s", "The values provided will never converge to a root.\n");

		falsePositionResults.steps = 0;
		falsePositionResults.root = 0;

		return falsePositionResults;
	}

	double estimatedRoot;
	int steps = 1;

	double fa = f(a);
	double f1 = f(b);
	double fRoot;

	do
	{
		estimatedRoot = a - (a - b) * fa / (fa - f1);
		fRoot = f(estimatedRoot);

		if (fa * fRoot < 0)
		{
			b = estimatedRoot;
			f1 = fRoot;
		}
		else
		{
			a = estimatedRoot;
			fa = fRoot;
		}
		steps++;

	} while (fabs(fRoot) > tolerance);

	// Results:
	falsePositionResults.steps = steps;
	falsePositionResults.root = estimatedRoot;

	return falsePositionResults;
}
