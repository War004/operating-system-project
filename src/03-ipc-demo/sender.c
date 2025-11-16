/*
 * 03-ipc-demo/sender.c
 *
 * This is the "sender" part of the demo.
 * It takes a PID from the command line and sends
 * the SIGUSR1 signal to that process.
 */

 #include <stdio.h>    // For printf
 #include <stdlib.h>   // For atoi, exit
 #include <signal.h>   // For kill, SIGUSR1
 #include <sys/types.h> // For pid_t
 
int main(int argc, char *argv[]) {
    // Check if the user provided a PID on the command line
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID_to_signal>\n", argv[0]);
        exit(1); // Exit with an error code
    }

    // Convert the command-line argument (a string) to an integer (pid_t)
    pid_t target_pid = atoi(argv[1]);

    if (target_pid <= 0) {
        fprintf(stderr, "Invalid PID: %s\n", argv[1]);
        exit(1);
    }

    printf("Sending SIGUSR1 signal to process %d...\n", target_pid);

    // Use the kill() system call to send the signal
    // kill() is poorly named; it's really a "signal-sender"
    if (kill(target_pid, SIGUSR1) == -1) {
        // This will fail if the PID doesn't exist
        perror("Error: kill() failed");
        exit(1);
    }

    printf("Signal sent successfully.\n");
    return 0;
}
