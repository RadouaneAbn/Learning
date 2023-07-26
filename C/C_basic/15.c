#include <stdio.h>   // Include standard input/output functions
#include <math.h>    // Include math functions like sqrtf() and powf()

float get_float(const char* message);  // Function prototype for getting a floating-point input from the user

int main()
{
    float x1, x2, y1, y2, root_square, X, Y;  // Declare variables to store user input and the calculated values

    x1 = get_float("Input x1 : ");   // Get the x1 coordinate from the user
    y1 = get_float("Input y1 : ");   // Get the y1 coordinate from the user
    x2 = get_float("Input x2 : ");   // Get the x2 coordinate from the user
    y2 = get_float("Input y2 : ");   // Get the y2 coordinate from the user

    // Calculate the distance between the two points using the distance formula:
    // square root of ( (x2 - x1)^2 + (y2 - y1)^2 )
    root_square = sqrtf(powf((x2 - x1), 2) + powf((y2 - y1), 2));

    printf("Distance between the said points : %.4f\n", root_square);  // Print the distance with 4 decimal places

    return 0;  // Return 0 to indicate successful program execution
}

// Function to get a floating-point input from the user
float get_float(const char* message)
{
    float input;  // Variable to store the user input
    printf("%s", message);  // Print the message to prompt the user
    scanf("%f", &input);    // Read the floating-point input from the user and store it in the 'input' variable
    return input;  // Return the user input
}
