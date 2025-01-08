# Pipex

## About the project

The **Pipex** is a 42 project that challenges students to implement a simplified version of the pipe functionality in Bash. The main objective is to consolidate knowledge about processes, input/output redirection, and inter-process communication in Unix systems.

---

## Features

- Simulate the behavior of the following Bash command:
  ```bash
  cmd1 < file_in | cmd2 > file_out
  ```
- Support for using two commands in sequence connected by a pipe.
- Management of input and output files for correct redirection.
- Proper error handling, such as:
  - Non-existent or permission-denied files.
  - Invalid commands.

---

## Technologies and Tools

- **Language**: C
- **Operating System**: Linux
- **POSIX functions**, such as:
  - `pipe()`
  - `dup2()`
  - `execve()`
  - `fork()`

---

## How to Compile

To compile the project, make sure you have the **gcc** compiler and **Make** installed. Use the following command:

```bash
make
```

The binary will be generated at the root of the project with the name `pipex`.

---
