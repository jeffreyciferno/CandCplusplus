/*
 * Author: Jeffrey Ciferno
 * Id: 1217664240
 * Email: jmcifern@asu.edu
 * Class: CSE310
 * Usage info:
 *    To compile: g++ -fopenmp -o prob5 prob5.cpp
 *    To run: ./prob5
 * To save the output in a file, redirect stdout to a file, i.e.,
 *    ./prob5 > outputFile.txt
 * where outputFile.txt is the desired name of the output file.
 */

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <omp.h>

using namespace std;

int sumWithLoop(int * A, int n);
int sumWithLoop_OMP(int * A, int n);
int sumRec(int * A, int n, int start, int end);
int sumRec_OMP(int * A, int n, int start, int end);

int main()
{
   double wtime;
   int n;
   printf ( " How many random numbers do you want to generate?\n" );
   scanf ( "%d", &n );
   int * A;
   A = new int[n];

   //generate n of random numbers
   srand( (unsigned) time(NULL) );

   for(int i = 0; i < n; i++)
   {
      A[i] = rand() % 100;
   }

   int num_procs = omp_get_num_procs ( );
   int max_threads = omp_get_max_threads ( );
   printf ( " Number of processors available = %d\n", num_procs );
   printf ( " Number of threads = %d\n", max_threads );

   //executing sumWithLoop and also measuring its execution time
   wtime = omp_get_wtime( );
   int sum1 = sumWithLoop(A, n);
   wtime = omp_get_wtime( ) - wtime;
   printf( "\n sum loop is %d\n", sum1 );
   printf ( " time  %14f\n\n", wtime );

   //executing sumWithLoop_OMP and also measuring its execution time
   wtime = omp_get_wtime ( );
   int sum2 = sumWithLoop_OMP(A, n);
   wtime = omp_get_wtime ( ) - wtime;
   printf( " sum loop OMP is %d\n", sum2 );
   printf ( " time  %14f\n\n", wtime );

   //executing sumRec and also mesuring its execution time
   wtime = omp_get_wtime( );
   int sum3 = sumRec(A, n, 0, n-1);
   wtime = omp_get_wtime( ) - wtime;
   printf( " sum recursion is %d\n", sum3 );
   printf ( " time  %14f\n\n", wtime );

   //executing sumRec_OMP and also mesuring its execution time
   wtime = omp_get_wtime ( );
   int sum4 = sumRec_OMP(A, n, 0, n-1);
   wtime = omp_get_wtime ( ) - wtime;
   printf( " sum recursion OMP is %d\n", sum4 );
   printf ( " time  %14f\n\n", wtime );
}

int sumWithLoop(int * A, int n)
{ int sum = 0;
for (int i = 0; i <= n; i++)
	{
	sum = sum + A[i]; //Adds sum to sum plus Array at i
	}
return sum; //Returns sum
}

int sumWithLoop_OMP(int * A, int n)
{int sum = 0;
#pragma omp parallel
#pragma omp for
for (int i = 0; i <= n; i++)
        {
        sum = sum + A[i]; //Adds sum to sum plus Array at i
        }
return sum; //Returns sum
}

int sumRec(int * A, int n, int start, int end)
{
int left = 0;
int right = 0;

	if (n == 0) //If number equals zero return a zero
	{
	   return 0;
	}
	else if (n == 1) //If number equals 1 return Array at zero(the only value)
	{
	   return A[0];
	}
	else // Else calulate both sides of the split array then sum
	{
	left = sumRec(A, n/2, start, end); //Left side sum
	right = sumRec(A + (n/2), n-(n/2), start, end); //Right side sum
	return left + right; //adds the two sums
	}
}

int sumRec_OMP(int * A, int n, int start, int end)
{
int left = 0;
int right = 0;

        if (n == 0) //If number equals zero return a zero
        {
           return 0;
        }
        else if (n == 1) //If number equals 1 return Array at zero(the only value)
        {
           return A[0];
        }
        else //else calculate both sides of the split array then sum
        {
	#pragma omp parallel
	#pragma omp sections
		{
		#pragma omp section
        	left = sumRec_OMP(A, (n/2), start, end); //Left side sum
		#pragma omp section
        	right = sumRec_OMP(A + (n/2), n-(n/2), start, end); //right side sum
        	}
	return left + right; //adds the two sums
	}
}

