/*
1) A box can be placed on top of another box only if both width 
and depth of the upper placed box are smaller than width and 
depth of the lower box respectively.

2) We can rotate boxes such that width is smaller than depth.
 For example, if there is a box with dimensions {1x2x3} where
  1 is height, 2×3 is base, then there can be three possibilities,
   {1x2x3}, {2x1x3} and {3x1x2} 

3) We can use multiple instances of boxes. 
What it means is, we can have two different 
rotations of a box as part of our maximum height stack.


Method 1 : dynamic programming using tabulation

1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of the original array. For simplicity, we consider width as always smaller than or equal to depth. 
2) Sort the above generated 3n boxes in decreasing order of base area.
3) After sorting the boxes, the problem is same as LIS with following optimal substructure property. 
MSH(i) = Maximum possible Stack Height with box i at top of stack 
MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i). 
If there is no such j then MSH(i) = height(i)
4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n
Following is the implementation of the above solution. */

/* Dynamic Programming implementation of Box Stacking problem */
#include<stdio.h>
#include<stdlib.h>

/* Representation of a box */
struct Box
{
// h --> height, w --> width, d --> depth
int h, w, d; // for simplicity of solution, always keep w <= d
};

// A utility function to get minimum of two integers
int min (int x, int y)
{ return (x < y)? x : y; }

// A utility function to get maximum of two integers
int max (int x, int y)
{ return (x > y)? x : y; }

/* Following function is needed for library function qsort(). We
use qsort() to sort boxes in decreasing order of base area.
Refer following link for help of qsort() and compare()
http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare (const void *a, const void * b)
{
	return ( (*(Box *)b).d * (*(Box *)b).w ) -
		( (*(Box *)a).d * (*(Box *)a).w );
}

/* Returns the height of the tallest stack that can be
formed with give type of boxes */
int maxStackHeight( Box arr[], int n )
{
/* Create an array of all rotations of given boxes
	For example, for a box {1, 2, 3}, we consider three
	instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
Box rot[3*n];
int index = 0;
for (int i = 0; i < n; i++)
{
	// Copy the original box
	rot[index].h = arr[i].h;
	rot[index].d = max(arr[i].d, arr[i].w);
	rot[index].w = min(arr[i].d, arr[i].w);
	index++;

	// First rotation of box
	rot[index].h = arr[i].w;
	rot[index].d = max(arr[i].h, arr[i].d);
	rot[index].w = min(arr[i].h, arr[i].d);
	index++;

	// Second rotation of box
	rot[index].h = arr[i].d;
	rot[index].d = max(arr[i].h, arr[i].w);
	rot[index].w = min(arr[i].h, arr[i].w);
	index++;
}

// Now the number of boxes is 3n
n = 3*n;

/* Sort the array 'rot[]' in non-increasing order
	of base area */
qsort (rot, n, sizeof(rot[0]), compare);

// Uncomment following two lines to print all rotations
// for (int i = 0; i < n; i++ )
// printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d);

/* Initialize msh values for all indexes
	msh[i] --> Maximum possible Stack Height with box i on top */
int msh[n];
for (int i = 0; i < n; i++ )
	msh[i] = rot[i].h;

/* Compute optimized msh values in bottom up manner */
for (int i = 1; i < n; i++ )
	for (int j = 0; j < i; j++ )
		if ( rot[i].w < rot[j].w &&
			rot[i].d < rot[j].d &&
			msh[i] < msh[j] + rot[i].h
			)
		{
			msh[i] = msh[j] + rot[i].h;
		}


/* Pick maximum of all msh values */
int max = -1;
for ( int i = 0; i < n; i++ )
	if ( max < msh[i] )
		max = msh[i];

return max;
}

/* Driver program to test above function */
int main()
{
Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
int n = sizeof(arr)/sizeof(arr[0]);

printf("The maximum possible height of stack is %d\n",
		maxStackHeight (arr, n) );

return 0;
}
