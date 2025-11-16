/*
 * 02-ignore-signal.c
 *
 * Demonstrates how to completely ignore a signal.
 * This program tells the OS to do *nothing* when it receives
 * a Ctrl+C (SIGINT) signal.
 */

 #include <stdio.h>    // For printf
 #include <unistd.h>   // For sleep, getpid
 #include <signal.h>   // For signal, SIGINT, SIG_IGN
 
 int main() {
     // Get and print the Process ID (PID) of this program.
     // You'll need this for the 'kill -9' command.
     pid_t my_pid = getpid();
     printf("Program running with PID: %d\n", my_pid);
     
     // Tell the OS: "When you receive a SIGINT signal,
     // just ignore it completely."
     // SIG_IGN is a special constant that means "Signal Ignore".
     signal(SIGINT, SIG_IGN);
 
     printf("I am now ignoring Ctrl+C. Nothing will happen.\n");
     printf("To stop me, open another terminal and type:\n");
     printf("kill -9 %d\n", my_pid);
 
     // Loop forever
     while (1) {
         printf("Working...\n");
         sleep(2);
     }
 
     return 0;
 }
