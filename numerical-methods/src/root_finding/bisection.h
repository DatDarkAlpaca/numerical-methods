#pragma once
#include <stdio.h>
#include "common.h"

results bisection(double a, double b, double (*f)(double), double tolerance)
{
	if (!validateInterval(a, b, f))
	{
		fprintf(stderr, "%s", "The values provided will never converge to a root.\n");
		return;
	}

	unsigned int steps = 1;

	float midpoint = 0;
	while ((b - a) >= tolerance)
	{
		midpoint = (a + b) / 2;

		if (f(midpoint) == 0.f)
			break;

		else if (f(midpoint) * f(a) < 0)
			b = midpoint;
		else
			a = midpoint;

		steps++;
	}

	// Results:
	results bisectionResults;
	bisectionResults.steps = steps;
	bisectionResults.root = midpoint;

	return bisectionResults;
}