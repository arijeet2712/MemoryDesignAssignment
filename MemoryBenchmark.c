#include <stdint.h>
#include <stdio.h>

#define ELEMENTS (1 << 16)
#define PASSES 8

static uint64_t data[ELEMENTS];

int main() {
  for (uint64_t i = 0; i < ELEMENTS; ++i)
    data[i] = i + 1;

  for (uint64_t pass = 0; pass < PASSES; ++pass) {
    for (uint64_t i = 0; i < ELEMENTS; ++i)
      data[i] = data[i] * 1664525 + i + pass;
  }

  uint64_t checksum = 0;
  for (uint64_t i = 0; i < ELEMENTS; ++i)
    checksum += data[i];

  printf("Memory checksum: %llu\n", (unsigned long long)checksum);
  return 0;
}
