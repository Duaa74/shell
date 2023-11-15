#include "main.h"
void shell(char **env) {
    char *command = NULL;
    size_t n = 0;

    while (1) {
        if (isatty(STDIN_FILENO))
            printf("$ "); // Display prompt if input is from a terminal

        if (getline(&command, &n, stdin) == -1) {
            free(command);
            exit(EXIT_FAILURE);
        }

        // Remove newline character from command
        command[strcspn(command, "\n")] = '\0';

        char *argv[MAX_COMMAND_LENGTH] = { NULL }; // Command arguments array
        int argc = 0;

        // Tokenize command into arguments
        char *token = strtok(command, " ");
        while (token != NULL && argc < MAX_COMMAND_LENGTH - 1) {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL; // Set the last argument to NULL

        char *final_command = get_location(argv[0]);

        if (final_command != NULL) {
            pid_t proc_id = fork();

            if (proc_id == -1) {
                free(command);
                free(final_command);
                exit(EXIT_FAILURE);
            }

            if (proc_id == 0) { // Child process
                execve(final_command, argv, env);
                perror("execve"); // If execve fails, print error
                exit(EXIT_FAILURE);
            } else { // Parent process
                wait(NULL); // Wait for child process to finish
            }

            free(final_command);
        } else {
            printf("%s: command not found\n", argv[0]);
        }
    }

    free(command);
}
