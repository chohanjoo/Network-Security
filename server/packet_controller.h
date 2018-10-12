#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int Packet_Handler(unsigned char *src, unsigned char **dst, int msgType, size_t* dst_len);

