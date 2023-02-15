#include "types.h"
#include "stat.h"
#include "user.h"

const int P = 15;
/*
This file is used to test the scheduler in proc.c. It will run several bubble sorts
in different processes with noTickets varying from argv[1], argv[1] + 10, ..., 100
Spected result: Process with most tickets finishes first, then second most, and so on.
*/

int main(int argc, char *argv[])
{
    int noTickets = 20;
    int biggestPID = 0;
    if (argc > 1)
        noTickets = atoi(argv[1]);

    for (int i = 0; i < P; i++)
    {
        int pid = fork(noTickets);

        if (pid == 0)
            exec("hello", argv);

        else if (i == P - 1)
            biggestPID = pid;

        noTickets *= 2;
    }
    for (int i = 0; i < P; i++)
        wait();

    printf(1, "BIGGEST PID IS %d\n", biggestPID);

    exit();
}