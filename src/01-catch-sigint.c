/*
 * 01-catch-sigint.c
 *
 * Demonstrates how to "catch" a signal and run custom code.
 * Instead of quitting on Ctrl+C (SIGINT), it prints a message.
 * It also keeps a counter and will exit after 5 attempts.
 */

 #include <stdio.h>    // For printf
 #include <unistd.h>   // For sleep
 #include <signal.h>   // For signal, SIGINT
 #include <stdlib.h>   // For exit
 
 // A global variable to count how many times Ctrl+C is pressed.
 // Note: Using global variables in handlers is generally risky,
 // but it's simple enough for this demo.
 volatile int sigint_count = 0;
 
 /*
  * This is the custom signal handler function.
  * The OS will run this function when the signal is received.
  */
 void handle_sigint(int sig) {
     sigint_count++;
     if (sigint_count >= 5) {
         printf("\nThat's enough! Exiting.\n");
         exit(0); // Exit the program
     } else {
         printf("\nOuch! Don't do that! Press %d more times to quit.\n", 5 - sigint_count);
     }
 }
 
 int main() {
     // Tell the OS: "When you receive a SIGINT signal,
     // don't do the default (quit). Instead, run my 'handle_sigint' function."
     signal(SIGINT, handle_sigint);
 
     printf("Program running. Try pressing Ctrl+C.\n");
     printf("I will only quit after 5 attempts.\n");
 
     // Loop forever, sleeping for 1 second at a time.
     // This keeps the program alive so it can receive signals.
     while (1) {
         sleep(1);
     }
 
     // This line will never be reached
     return 0;
 }
