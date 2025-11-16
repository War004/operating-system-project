# Linux Signal Demonstrations

A collection of C programs demonstrating Linux Signals. This project shows how to catch `SIGINT` (Ctrl+C), ignore signals, and use signals for basic Inter-Process Communication (IPC).

Inspired by the 'Core Dumped' YouTube channel:
[Signals: Make Ctrl+C Do Anything You Want](https://www.youtube.com/watch?v=m6WXrC9Mxzo)

---

## 🛠️ How to Compile and Run

This project includes a `Makefile` to simplify compilation. You will need `gcc` (or `clang`) and `make` installed.

1.  **Clone the repository** (or download and extract the files).

2.  **Create the `build` directory:**
    ```bash
    mkdir build
    ```

3.  **Compile all programs:**
    ```bash
    make all
    ```

4.  **Run a specific example** (see below).

5.  **To clean up** compiled files:
    ```bash
    make clean
    ```

---

## 🚀 The Examples

### 1. `src/01-catch-sigint.c`

* **What it does:** Demonstrates how to "catch" the `SIGINT` signal (sent by `Ctrl+C`).
* **How it works:** Instead of quitting, the program catches the signal and prints a message ("Ouch! Don't do that!"). It keeps a counter and will only exit after you press `Ctrl+C` 5 times.
* **To Run:**
    ```bash
    ./build/01-catch-sigint
    ```

### 2. `src/02-ignore-signal.c`

* **What it does:** Shows how to *completely ignore* a signal.
* **How it works:** This program tells the OS to ignore `SIGINT`. When you press `Ctrl+C`, *nothing* happens. It prints its own PID so you can stop it.
* **To Run:**
    ```bash
    ./build/02-ignore-signal
    ```
* **To Stop:** You must open a **second terminal** and use the `kill -9` command with the PID it printed.
    ```bash
    kill -9 <PID_from_program>
    ```

### 3. `src/03-ipc-demo/`

* **What it does:** A two-part demo showing how signals are used for Inter-Process Communication (IPC).
* **How it works:**
    1.  Run the `receiver` in one terminal. It will print its PID and wait.
    2.  Run the `sender` in a second terminal, giving it the receiver's PID as an argument.
    3.  The `sender` uses the `kill()` system call to send a `SIGUSR1` signal.
    4.  The `receiver` catches this signal and prints ">>> Signal Received! <<<".
* **To Run (Terminal 1):**
    ```bash
    ./build/receiver
    # It will print: Receiver PID is: 12345
    ```
* **To Run (Terminal 2):**
    ```bash
    # Use the PID from Terminal 1
    ./build/sender 12345
    ```
---

## Output

<img width="393" height="297" alt="image" src="https://github.com/user-attachments/assets/0b351136-4faf-4c05-a22b-847252e060a3" />

--

<img width="932" height="490" alt="image" src="https://github.com/user-attachments/assets/c000e9d1-05e3-4365-88ab-932dd2bf957a" />

--

<img width="912" height="252" alt="image" src="https://github.com/user-attachments/assets/5d78c8ef-83ef-4aaf-8a4f-d3f5da69665f" />
