#pragma once
#include <stdio.h>
#include "common.h"

results newton(double xn, double (*f)(double), double (*derivative)(double), double tolerance)
{
	unsigned int steps = 1;
	double root;
	while (true)
	{
		root = xn - (f(xn) / derivative(xn));

		if (f(root) > -tolerance && f(root) < tolerance)
			break;

		steps++;
		xn = root;
	}

	results newtonResults;
	newtonResults.root = root;
	newtonResults.steps = steps;

	return newtonResults;
}