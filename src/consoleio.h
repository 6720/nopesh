// Used in the commented-out function in consoleio.c
// #define READLINE_BUFFER_SIZE 1024

#define TOKEN_BUFFERSIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

char** nopesh_split_line(char* line);

char* nopesh_read_line(void);
