# Inter-Process Communication (IPC) Project

## Overview
This project focuses on implementing and demonstrating **Inter-Process Communication (IPC)** using **pipes** to facilitate data exchange between processes. The goal is to showcase how different processes communicate and share data efficiently. The project may include both **custom programs** and **existing Linux utilities** to demonstrate IPC concepts effectively.

## Build and Run Instructions

### Prerequisites
Ensure you have the following installed on your Linux system:
- **GCC** (for compiling C programs)
- **Make** (for build automation, optional but recommended)

### Installation
```bash
sudo apt update
sudo apt install build-essential
```

### Building the Project
Navigate to the project directory and compile the C source files:
```bash
gcc -o ipc_demo ipc_demo.c
```

If using multiple C files, compile with:
```bash
gcc -o ipc_demo file1.c file2.c -lpthread
```

### Running the Program
Execute the compiled program:
```bash
./ipc_demo
```

If the project involves multiple communicating programs:
```bash
./producer | ./consumer
```

## Core Requirements & Implementation
 Process Communication via Pipes
- Implement or demonstrate communication between **two or more processes** using **pipes (`|`)**.
- Ensure that data is passed efficiently from one process to another.

Data Flow Explanation
- Clearly illustrate how data moves between processes.
- Provide examples of commands or programs involved in data exchange.

## Documentation Requirements
- Explanation of **processes used** and their role in the communication.
- Detailed description of **data flow through pipes**.
- Error handling strategies (e.g., handling broken pipes or invalid data).
- Example outputs from successful program executions.

## Testing Guidelines

### 1. Data Integrity Testing
- Ensure that data passed between processes **remains unchanged and correctly transmitted**.
- Example: Pass structured data (e.g., JSON or CSV) between producer and consumer processes and verify correctness.

### 2. Error Handling Validation
- Test how the program handles errors such as **broken pipes or invalid inputs**.
- Example: Force a pipe closure mid-communication and check if the program exits gracefully.

### 3. Performance Benchmarking
- Measure the **throughput and latency** of data communication via pipes.
- Example: Record the time taken to transmit large data files between processes.

## Dependencies
- **GCC** (for compiling C programs)
- **Make** (optional, for build automation)
- **Standard C Library (`unistd.h`, `stdio.h`, `stdlib.h`, `fcntl.h`)** for IPC implementation

Install dependencies using:
```bash
sudo apt install build-essential
