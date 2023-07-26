#include <stdio.h>

int main()
{
    int x = 0; // Initialize a variable 'x' to count duplicate elements
    int E; // Variable to store the number of elements to be stored in the array
    printf("Input the number of elements to be stored in the array : ");
    scanf("%i", &E); // Read the number of elements from the user
    printf("Input %i elements in the array : \n", E);

    long int N[E]; // Declare an array 'N' of size 'E' to store the elements

    // Read the elements from the user and store them in the array 'N'
    for (int i = 0; i < E; i++)
    {
        printf("element - %i : ", i);
        scanf("%ld", &N[i]);
    }

    // Loop through the array to check for duplicate elements
    for (int j = 0; j < E; j++)
    {
        for (int k = 0; k < E; k++)
        {
            if (j != k) // Ensure we are not comparing an element with itself
            {
                if (N[j] == N[k]) // Check if two elements are equal
                {
                    x++; // If equal, increment the count of duplicate elements
                }
            }
        }
    }
    // Since we count each duplicate twice (once for each pair), we divide 'x' by 2 to get the total number of duplicate elements
    printf("Total number of duplicate elements found in the array is : %i\n", x/2);
}
