#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int CompareSortedArrays(int *A, int *B)
{
    int i;
    
      //compare the two arrays
    for(i=0; i<6; i++)
     if (*(A+i) != *(B+i))
        {
            printf("\nSorry, try again.\n");
            return 0;
        }
        
    printf("\nCongratulations, you won!.\n");
    return 1;
}

void InsertionSort(int A[], int size)
{
	for(int i=1; i<size; i++)
	{
		int value = A[i];
		int aux = i;
		while( aux>0 && A[aux-1]>value)
		{
			A[aux] = A[aux-1];
			aux--;
		}
		A[aux] = value ;
	}
}

// function to generate 6 random numbers
int * getRandom ()
{
  static int r[6];
  int i, j;

  /* set the seed */
  srand ((unsigned) time (0));
  printf (" And the LOTTO numbers are... \n");

  /* generate an array of random numbers */
  for (i = 0; i < 6; ++i)
    {
      r[i] = rand () % 50;
      
      /* check that the newly added number is not already in the array */
      for (j = 0; j < i; j++)
	  while (r[j] == r[i])
	  {
	    r[i] = rand () % 50;
	    break;
	  }
	  /* print the numbers */
      printf ("%d | ", r[i]);
    }

  return r;
}

// funtion that gets the numbers from the user
int * getUserInput ()
{
  static int r[6];
  int i, j;
  
  printf ("Please insert 6 different numbers between 0 and 49.\n");

  for (i = 0; i < 6; ++i)
    {
      printf ("r[%d]= ", i);
      scanf (" %d", &r[i]);
      
      /* check that user doesn't write a number greater than 49 */
      while (r[i] > 49)
	{
	  printf
	    ("You wrote %d, which is greater than 49, please write another number.\n",
	     r[i]);
	  scanf (" %d", &r[i]);
	}
	  
	  /* check that the newly added number is not already in the array */
      for (j = 0; j < i; j++)
	  while (r[j] == r[i])
	  {
	    printf ("You wrote %d twice, please write another number.\n", r[i]);
	  scanf (" %d", &r[i]);
	    break;
	  }
    }

  return r;
}


int
main ()
{
  /* a pointer to an int */
  int  *user_values, *random_numbers;
  int i;

  user_values = getUserInput ();
  InsertionSort(user_values, 6);
  random_numbers = getRandom ();
  InsertionSort(random_numbers, 6);
  
  CompareSortedArrays(user_values, random_numbers);

}
