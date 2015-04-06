#include "consoleio.h"
#include <stdlib.h>
#include <stdio.h>

char* nopesh_read_line(void) {
        char* line = NULL;
        ssize_t buffersize = 0; // Have getline() allocate a buffer for us
        getline(&line, &buffersize, stdin);
        return line;
}

// This is a good learning experience, but modern UNIX C stdlibs will have the 
// getline() used in the above implementation. 
/*char* nopesh_read_line(void) {
        int buffersize = READLINE_BUFFER_SIZE;
        int position = 0;
        char* buffer = malloc(sizeof(char) * buffersize);
        int c;

        if(!buffer) {
                fprintf(stderr, "nopesh: memory allocation error\n");
                exit(1);
        }

        while(1) {
                // Read a character
                c = getchar();

                // If we hit EOF or newline, replace with a NUL character and
                // return
                if(c == EOF || c == '\n') {
                        buffer[position] = '\0';
                        return buffer;
                } else {
                        buffer[position] = c;
                }
                ++position;

                // If we exceed the buffer's size, and we're not done, 
                // reallocate
                if(position >= buffersize) {
                        buffersize += READLINE_BUFFER_SIZE;
                        buffer = realloc(buffer, buffersize);
                        if(!buffer) {
                                fprintf(stderr, "nopesh: memory reallocation error");
                                exit(1);
                        }
                }
        }
}*/
