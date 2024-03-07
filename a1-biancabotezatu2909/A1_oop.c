/* 1.
a. Generate all the prime numbers smaller than a given natural number n.
b. Given a vector of numbers, find the longest increasing contiguous
subsequence, such the sum of that any 2 consecutive elements is a prime number.
*/

#include <stdio.h>

void print_menu()
{
	/*
	-> the function prints the menu options
	-> no parameters
	-> doesn't return anything
	*/

	printf("1) Read a vector\n");
	printf("2) Solve a)\n");
	printf("3) Solve b)\n");
	printf("4) Exit\n");

}

int read_vector(int vector[])
{
	/*
	-> the function performs reading the length of a vector and the vector from the keyboard
	-> parameters: vector, n-length
	-> return the length
	*/
	int n;
	printf("->Dimension of vector = ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &vector[i]);
	return n;
}


int is_prime(number)
{
	/*
	-> the function checks if a given number is prime
	-> parameter: the number to be checked
	-> returns 1 if it is prime, 0 otherwise
	*/
	int ok = 1;
	for (int i = 2; i * i <= number; i++)
		if (number % i == 0)
			ok = 0;
	return ok;

}

void print_vector(int vector[100], int n)
{
	/*
	-> the function prints the vector
	*/
	for (int i = 0; i < n; i++)
		printf("%d ", vector[i]);
	printf("\n");
}
void solve_a()
{
	/*
	-> the function solves the a) functionality
	-> no parameters
	-> doesn't return anything
	*/
	int n, nr = 2, array_prime[100], poz = 0;
	printf("n = ");
	scanf_s("%d", &n);
	while (nr < n)
	{
		if (is_prime(nr) == 1)
		{
			array_prime[poz] = nr;
			poz++;
		}
		nr++;
	}
	printf("The prime numbers smaller than n are: ");

	print_vector(array_prime, poz);
}

void solve_b(int vector[], int n)
{
	/*
	-> the function solves b) functionality
	-> no parameters
	-> doesn't return anything
	*/
	int sum = 0, maxim, length = 1, best_end = 0, end = 0;
	//n = read_vector(vector, n);
	maxim = 0;

	printf("-> The vector is:\n");
	print_vector(vector, n);
	printf("\n");


	for (int i = 0; i <= n - 1; i++)
	{
		if (vector[i] < vector[i + 1] && is_prime(vector[i] + vector[i + 1]))
		{
			length++;
			end = i + 1;
			//i--;
		}
		else
		{
			if (length > maxim)
			{
				maxim = length;
				best_end = end;
				length = 1;
			}
		}
	}
	printf("-> The length of the longest subsequence is: ");
	printf("%d\n", maxim);
	printf("-> The longest subsequence is: ");
	for (int i = best_end - maxim + 1; i <= best_end; i++)
		printf("%d ", vector[i]);
	printf("\n");

}


int main()
{

	int n, vect[100], maxim, length_vector = 0;
	char option = 'q';

	while (1)
	{
		print_menu();
		printf("Choose an option: ");
		scanf_s(" %c", &option);
		if (option == '1')
			length_vector = read_vector(vect, length_vector);
		else if (option == '2')
			solve_a();
		else if (option == '3')
			solve_b(vect, length_vector);
		else if (option == '4')
			break;
		else
			printf("Incorrect input\n");
	}
	return 0;
}