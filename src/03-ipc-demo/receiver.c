/*
 * 03-ipc-demo/receiver.c
 *
 * This is the "receiver" part of the demo.
 * It prints its PID and then waits to receive a SIGUSR1 signal
 * from the "sender" program.
 */

 #include <stdio.h>    // For printf
 #include <unistd.h>   // For sleep, getpid
 #include <signal.h>   // For signal, SIGUSR1
 
 // This handler will run when SIGUSR1 is received
 void handle_sigusr1(int sig) {
     printf("\n>>> Signal Received! <<<\n");
 }
 
 int main() {
     // Get and print this program's Process ID (PID)
     pid_t my_pid = getpid();
     printf("Receiver PID is: %d\n", my_pid);
     printf("Waiting for a SIGUSR1 signal...\n");
 
     // Tell the OS to run 'handle_sigusr1' when a SIGUSR1 is received
     signal(SIGUSR1, handle_sigusr1);
 
     // Loop forever, waiting for signals
     while (1) {
         sleep(1);
     }
 
     return 0;
 }
