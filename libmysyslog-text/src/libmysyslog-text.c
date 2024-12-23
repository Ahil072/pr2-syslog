#include "libmysyslog-text.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

static const char* log_levels[] = {"DEBUG", "INFO", "WARN", "ERROR", "CRITICAL"};

int log_to_text(const char* msg, int level, const char* path) {
    FILE* file = fopen(path, "a");
    if (!file) return -1;

    char proc_path[PATH_MAX];
    if (readlink("/proc/self/exe", proc_path, sizeof(proc_path)) == -1) {
        strcpy(proc_path, "unknown");
    }

    time_t now = time(NULL);
    fprintf(file, "%ld %s [%s] (PID: %d) %s\n", now, log_levels[level], proc_path, getpid(), msg);
    fclose(file);
    return 0;
}
