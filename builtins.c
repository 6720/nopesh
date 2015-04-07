#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Forward declaractions so that we can use them in the related variables
int nopesh_cd(char** args);
int nopesh_help(char** args);
int nopesh_exit(char** args);

// Array of built-in commands
char* builtin_str[] = {
        "cd",
        "help",
        "exit"
};

// References (wording?) to the actual builtin functions
int (*builtin_func[])(char**) = {
        &nopesh_cd,
        &nopesh_help,
        &nopesh_exit
};

int nopesh_num_builtins(void) {
        return sizeof(builtin_str) / sizeof(char*);
}

// Builtin implementations
int nopesh_cd(char** args) {
        if(args[1] == NULL) {
                // TODO: Return to home directory
                fprintf(stderr, "nopesh: invalid cd location\n");
                return 2;
        } else {
                int chdir_status = chdir(args[1]);
                if(chdir_status != 0) {
                        perror("nopesh");
                }
                return chdir_status;
        }
}

int nopesh_help(char** args) {
        fprintf(stderr, "Not yet implemented!\n");
        return 2;
}

int nopesh_exit(char** args) {
        fprintf(stderr, "Not yet implemented!\n");
        return 2;
}
