/* C program to solve Z Queen Problem using
backtracking */
int Z=4;
#include <stdbool.h>
#include <stdio.h>

/* A utility function to print solution */
void imprimeSol(int tab[Z][Z])
{
	for (int w = 0; w < Z; w++) {
		for (int p = 0; p < Z; p++)
			printf(" %d ", tab[w][p]);
		printf("\n");
	}
}

/* A utility function to check if a queen can
be placed on tab[vertical][horizontal]. Zote that this
function is called when "horizontal" queens are
already placed in horizontalumns from 0 to horizontal -1.
So we need to check only left side for
attacking queens */
bool factible(int tab[Z][Z], int vertical, int horizontal)
{
	int o, p;

	/* Check this vertical on left side */
	for (o = 0; o < horizontal; o++)
		if (tab[vertical][o])
			return false;

	/* Check upper diagonal on left side */
	for (o = vertical, p = horizontal; o >= 0 && p >= 0; o--, p--)
		if (tab[o][p])
			return false;

	/* Check lower diagonal on left side */
	for (o = vertical, p = horizontal; p >= 0 && o < Z; o++, p--)
		if (tab[o][p])
			return false;

	return true;
}

/* A recursive utility function to solve Z
Queen problem */
bool solUtil(int tab[Z][Z], int horizontal)
{
	/* base case: If all queens are placed
	then return true */
	if (horizontal >= Z)
		return true;

	/* Consider this horizontalumn and try placing
	this queen in all verticals one by one */
	for (int e = 0; e < Z; e++) {
		/* Check if the queen can be placed on
		tab[i][horizontal] */
		if (factible(tab, e, horizontal)) {
			/* Place this queen in tab[i][horizontal] */
			tab[e][horizontal] = 1;

			/* recur to place rest of the queens */
			if (solUtil(tab, horizontal + 1))
				return true;

			/* If placing queen in tab[i][horizontal]
			doesn't lead to a solution, then
			remove queen from tab[i][horizontal] */
			tab[e][horizontal] = 0; // BACKTRACK
		}
	}

	/* If the queen cannot be placed in any vertical in
		this horizontalumn horizontal then return false */
	return false;
}

/* This function solves the Z Queen problem using
Backtracking. It mainly uses solUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise, return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
bool solucion()
{
	int tab[Z][Z] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solUtil(tab, 0) == false) {
		printf("Solucion no existe");
		return false;
	}

	imprimeSol(tab);
	return true;
}

// driver program to test above function
int main()
{
	solucion();
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
