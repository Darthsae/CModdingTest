#ifndef LOGGING_H
#define LOGGING_H
#define DEBUG
#ifdef DEBUG
#define LOG_INFO(a, ...) printf("[INF]: " ## a ## "\n", ##__VA_ARGS__)
#define LOG_DEBUG(a, ...) printf("[DBG]: " ## a ## "\n", ##__VA_ARGS__)
#define LOG_WARNING(a, ...) printf("[WRN]: " ## a ## "\n", ##__VA_ARGS__)
#define LOG_ERROR(a, ...) printf("[ERR]: " ## a ## "\n", ##__VA_ARGS__) 
#endif
#ifndef DEBUG
#define LOG_INFO(a, ...)
#define LOG_DEBUG(a, ...)
#define LOG_WARNING(a, ...)
#define LOG_ERROR(a, ...)
#endif
#endif