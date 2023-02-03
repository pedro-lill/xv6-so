#include "types.h"
#include "stat.h"
#include "user.h"

#define N 100
#define SIZE 900

int isSorted(int *array)
{
    for (int i = 1; i < SIZE; i++)
        if (array[i - 1] > array[i])
            return 0;

    return 1;
}

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void initializeArray(int *array)
{

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = SIZE - i;
    }
}

void bubble(int *array)
{
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;

        for (int i = 0; i < SIZE - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                swapped = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int mypid = getpid();

    for (int i = 0; i < N; i++)
    {
        int array[SIZE];
        initializeArray(array);
        bubble(array);
    }
    printf(1, "BUBBLE WITH PID %d FINISHED\n", mypid);
    exit();
}
