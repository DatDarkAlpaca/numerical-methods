#pragma once
#include <stdbool.h>

#define TOLERANCE 0.001

// Intermediate value theorem:
bool validateInterval(double a, double b, double (*f)(double))
{
	return f(a) * f(b) < 0;
}

// Result fetching:
struct results
{
	double root;
	unsigned int steps;
} typedef results;

void printResults(const results* const results)
{
	printf("Root: %f\n", results->root);
	printf("Steps: %d\n", results->steps);
}