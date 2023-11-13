#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int getOperand(char operandName)
{
    int operand;
    printf("Enter operand '%c': ", operandName);
    while (scanf("%d", &operand) != 1)
    {
        printf("Invalid input. Please enter an integer for operand '%c': ", operandName);
        // Clear input buffer
        while (getchar() != '\n');
    }
    return operand;
}

int main(void)
{
    int choice;
    int num1, num2;

    do
    {
        num1 = getOperand('a');
        num2 = getOperand('b');

        printf("Specify the operation to perform (0:add, 1:subtract, 2:multiply, 3:divide, 4:exit): ");
        while (scanf("%d", &choice) != 1 || choice < 0 || choice > 4)
        {
            printf("Invalid input. Please enter a valid operation (0-4): ");
            // Clear input buffer
            while (getchar() != '\n');
        }

        // Array of function pointers
        int (*operations[])(int, int) = {add, subtract, multiply, divide, NULL};

        // Check if the choice is valid
        if (choice >= 0 && choice <= 3)
        {
            // Assign the selected function to the function pointer
            int (*operation)(int, int) = operations[choice];

            // Check if the operation is not NULL (exit option is NULL)
            if (operation != NULL)
            {
                int result = operation(num1, num2);
                printf("Result: %d\n", result);
            }

            // Additional message indicating the program is ready for the next input
            printf("Ready for the next input or operation.\n");
        }
    } while (choice != 4);

    printf("Exiting the program.\n");

    return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add(int a, int b)
{
    printf("Adding 'a' and 'b'\n");
    return a + b;
}

int subtract(int a, int b)
{
    printf("Subtracting 'b' from 'a'\n");
    return a - b;
}

int multiply(int a, int b)
{
    printf("Multiplying 'a' and 'b'\n");
    return a * b;
}

int divide(int a, int b)
{
    if (b != 0)
    {
        printf("Dividing 'a' by 'b'\n");
        return a / b;
    }
    else
    {
        printf("Cannot divide by zero\n");
        return -1;
    }
}
