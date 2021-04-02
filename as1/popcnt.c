#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BUF_SIZE 33

uint8_t simple_popcnt(uint32_t n)
{
    uint8_t count = 0;
    for (uint8_t i = 0; !!n; ++i) {
        count += n & 0x1;
        n >>= 1;
    }
    return count;
}

uint8_t better_popcnt(uint32_t n)
{
    uint8_t count = 0;
    while (!!n) {
        n &= n - 1;
        ++count;
    }
    return count;
}

uint32_t uint2bin(uint32_t n, char buf[BUF_SIZE])
{
    memset(buf, '0', BUF_SIZE);
    buf[BUF_SIZE - 1] = 0;

    uint32_t len = 1;
    for (uint32_t buf_index = BUF_SIZE - 2; !!n; --buf_index, ++len) {
        buf[buf_index] = (n & 0x1) + '0';
        n >>= 1;
    }
    return len;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: ./popcnt <n>\n");
        return 1;
    }

    char * n_str = argv[1];
    char * n_str_end = n_str + strlen(n_str);
    int base = strncmp(n_str, "0x", 2) == 0 ? 16 : 10;
    uint32_t n = strtol(n_str, &n_str_end, base);

    char binary_n_buf[BUF_SIZE];
    uint32_t len = uint2bin(n, binary_n_buf);

    printf("Number %u [%s] has set bits: better_popcnt(%d), simple_popcnt(%d)\n",
           n, &binary_n_buf[BUF_SIZE - len],
           better_popcnt(n),
           simple_popcnt(n));
    return 0;
}
