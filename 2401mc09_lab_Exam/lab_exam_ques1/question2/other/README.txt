Name: Tanvi Begari
Roll Number: [2401mc09]
Set 1

Question 1: Counting Semaphores for Process Synchronization
1. Added sem.c to implement a table of 8 counting semaphores protected by a spinlock.
2. Updated main.c and defs.h to initialize the semaphore table during kernel startup.
3. Modified syscall.h, syscall.c, and sysproc.c to register sem_init, sem_wait, and sem_post system calls.
4. Updated user.h and usys.S to expose the semaphore system calls to user programs.
5. Modified Makefile to compile sem.o and include the synctest user program.
6. Added synctest.c to synchronize three child processes to print ABC five times in order, followed by Done.
