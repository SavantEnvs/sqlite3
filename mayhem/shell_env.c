/* Mock of the process environment for the fuzzed sqlite3 shell: the shell's ".shell"/".system"
** and "|cmd" redirections would run fuzzer-chosen commands on the host. Defined in the executable,
** these take precedence over libc's. */
#include <stdio.h>
#include <errno.h>
int system(const char *zCmd){ (void)zCmd; errno = EPERM; return -1; }
FILE *popen(const char *zCmd, const char *zMode){ (void)zCmd; (void)zMode; errno = EPERM; return 0; }
