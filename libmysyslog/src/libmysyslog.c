#include "libmysyslog.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

static const char* log_levels[] = {"DEBUG", "INFO", "WARN", "ERROR", "CRITICAL"};

int log_to_text(const char* msg, int level, const char* path);
int log_to_json(const char* msg, int level, const char* path);

int mysyslog(const char* msg, int level, int driver, int format, const char* path) {
    if (driver == TEXT_DRIVER) {
        return log_to_text(msg, level, path);
    } else if (driver == JSON_DRIVER) {
        return log_to_json(msg, level, path);
    } else {
        return -1; // Unsupported driver
    }
}

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

int log_to_json(const char* msg, int level, const char* path) {
    FILE* file = fopen(path, "a");
    if (!file) return -1;

    char proc_path[PATH_MAX];
    if (readlink("/proc/self/exe", proc_path, sizeof(proc_path)) == -1) {
        strcpy(proc_path, "unknown");
    }

    time_t now = time(NULL);
    fprintf(file, "{\"timestamp\":%ld,\"log_level\":\"%s\",\"process_path\":\"%s\",\"pid\":%d,\"message\":\"%s\"}\n",
            now, log_levels[level], proc_path, getpid(), msg);
    fclose(file);
    return 0;
}
