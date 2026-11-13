#include <stdint.h>
#include <stdio.h>

int main() {
  const uint64_t iterations = 1000000;
  double a = 1.0;
  double b = 1.5;
  double c = 2.0;
  double d = 2.5;

  for (uint64_t i = 0; i < iterations; ++i) {
    a = a * 1.0000001 + 0.0000001;
    b = b * 0.9999999 + 0.0000002;
    c = c * 1.0000002 + 0.0000003;
    d = d * 0.9999998 + 0.0000004;
  }

  printf("FP checksum: %.12f\n", a + b + c + d);
  return 0;
}
