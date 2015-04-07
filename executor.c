#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "builtins.h"
#include "executor.h"

int nopesh_launch(char** args);

int nopesh_execute(char** args) {
        int i;

        if(args[0] == NULL) {
                // Empty command
                return 1;
        }

        // Builtins
        for(i = 0; i < nopesh_num_builtins(); i++) {
                if(strcmp(args[0], builtin_str[i]) == 0) { // Again, couldn't we just use "!strcmp(...)"?
                        return (*builtin_func[i])(args);
                }
        }
        
        // No can find! Make system get it from path
        return nopesh_launch(args);
}

int nopesh_launch(char** args) {
        pid_t pid; // Forked process ID
        pid_t wpid; // Wait process ID
        int status; // Status of child

        pid = fork();
        if(pid == 0) {
                // Child process
                if(execvp(args[0], args) == -1) {
                        perror("nopesh");
                } 
                exit(1);
        } else if(pid < 0) {
                // Error fork()ing
                perror("nopesh");
        } else {
                // Parent process
                do {
                        wpid = waitpid(pid, &status, WUNTRACED);
                } while(!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        return 1;
}
