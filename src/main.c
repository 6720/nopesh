#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "consoleio.h"
#include "controlchars.h"
#include "executor.h"
#include "statuscodes.h"

#define MAIN_STRING_BUFFER_SIZE 1024

void nopesh_shell_loop(void);

int main(int argc, char** argv) {
        // Yay! We have a shell!
        
        // TODO: Init, config, etc.
        
        // Actually run the shell
        nopesh_shell_loop();
        
        // TODO: Cleanup
        
        return 0;
}

void nopesh_shell_loop(void) {
        char* line;
        char** args;
        int status;
        status = 0;
        do {
                printf("nopesh> "); 
                line = nopesh_read_line();
                if(line[0] == EOF || line[0] == 0) { // Seems to be ^D
                        free(line);
                        break;
                }
                if(line[0] == CONTROL_FF) { // ^L
                        line = malloc(sizeof(char) * 5);
                        if(!line) {
                                fprintf(stderr, "nopesh: error allocating memory");
                                exit(1);
                        }
                        strcat(line, "clear");
                }
                args = nopesh_split_line(line);
                status = nopesh_execute(args);

                free(line);
                free(args);
        } while(status != EXIT_CODE);
}
