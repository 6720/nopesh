#include <stdlib.h>
#include <stdio.h>
#include "consoleio.h"
#include "statuscodes.h"
#include "executor.h"

void nopesh_shell_loop(void);

int main(int argc, char** argv) {
        // Yay! We have a shell!
        nopesh_shell_loop();
        return 0;
}

void nopesh_shell_loop(void) {
        char* line;
        char** args;
        int status;
        do {
                printf("nopesh> "); 
                line = nopesh_read_line(); // read line
                args = nopesh_split_line(line); // split line into stuff
                status = nopesh_execute(args); // execute();

                free(line);
                free(args);
        } while(status != EXIT_CODE);
}
