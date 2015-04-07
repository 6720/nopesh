#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

char* get_home(void) {
        struct passwd *pw = getpwuid(getuid());
        return pw->pw_dir;
}
