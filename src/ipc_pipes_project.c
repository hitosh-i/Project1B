#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close write end of the pipe
        printf("Child process reading from pipe:\n");

        ssize_t bytesRead;
        while ((bytesRead = read(pipefd[0], buffer, BUFFER_SIZE)) > 0) {
            write(STDOUT_FILENO, buffer, bytesRead);
        }

        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipefd[0]); // Close read end of the pipe

        // Execute "ls -l" and send output through the pipe
        FILE *ls = popen("ls -l", "r");
        if (!ls) {
            perror("popen");
            exit(EXIT_FAILURE);
        }

        ssize_t bytesRead;
        while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, ls)) > 0) {
            write(pipefd[1], buffer, bytesRead);
        }

        pclose(ls);
        close(pipefd[1]); // Close write end of the pipe
        wait(NULL); // Wait for child to finish
    }
    return 0;
}
