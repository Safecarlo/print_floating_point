#include <stdio.h>  // printf
#include <stdlib.h> // strtod
#include <stdint.h> // uint_32
#include <string.h> // strcmp

// float constant
#define SIZE_32 32
#define RANGE_32 8
#define PRECISION_32 23

//
typedef uint32_t u32;

// help for print in hexadecimal and binary floats
typedef union
{
  float f;
  u32 u;
} f2u;

// print float in binary
void printf_f2b(f2u _c)
{
  // sign
  printf("%u", ((_c.u) >> (SIZE_32 - 1)) & 1);
  
  // Separate
  printf(" ");

  // exponent
  for (u32 i = 1; i < RANGE_32 + 1; i++)
    {
      printf("%u", ((_c.u) >> (SIZE_32 - i - 1)) & 1);
    }

  // Separate
  printf(" ");

  // matisse
  for (u32 i = RANGE_32 + 1; i < RANGE_32 + PRECISION_32 + 1; i++)
    {
      printf("%u", ((_c.u) >> (SIZE_32 - i - 1)) & 1);
    }
}

// double constant
#define SIZE_64 64
#define RANGE_64 11
#define PRECISION_64 52

//
typedef uint64_t u64;

// help for print in hexadecimal and binary doubles
typedef union
{
  double d;
  u64 u;
} d2u;

// print double in binary
void printf_d2b(d2u _c)
{
  // sign
  printf("%lu", ((_c.u) >> (SIZE_64 - 1)) & 1);
  
  // Separate
  printf(" ");

  // exponent
  for (u64 i = 1; i < RANGE_64 + 1; i++)
    {
      printf("%lu", ((_c.u) >> (SIZE_64 - i - 1)) & 1);
    }

  // Separate
  printf(" ");

  // matisse
  for (u64 i = RANGE_64 + 1; i < RANGE_64 + PRECISION_64 + 1; i++)
    {
      printf("%lu", ((_c.u) >> (SIZE_64 - i - 1)) & 1);
    }
}

//
int main(int argc, char **argv)
{
  // Check input
  if (argc != 3)
    return printf("Usage: %s [TYPE] [FLOATING POINT NUMBER]\n", argv[0]), 1;

  // Type
  char *type = argv[1];

  if (strcmp(type, "float") == 0) // float
    {
      // Get float
      float a = strtod(argv[2], NULL);
      float b = 0.0;
      float c = a + b; // compute to activate verificarlo ob

      // Using union tricks
      f2u _c = {.f = c};

      // Print
      printf("decimal                   : %f\n", _c.f);
      printf("scientific                : %e\n", _c.f);
      printf("hexadecimal floating point: %a\n", _c.f);
      printf("hexadecimal integer       : 0x%x\n", _c.u);
      printf("binary                    : ");
      printf_f2b(_c);
      printf("\n");
    }
  else if (strcmp(type, "double") == 0) // double
    {
      // Get double
      double a = strtod(argv[2], NULL);
      double b = 0.0;
      double c = a + b; // compute to activate verificarlo ob

      // Using union tricks
      d2u _c = {.d = c};

      // Print
      printf("decimal                   : %f\n", _c.d);
      printf("scientific                : %e\n", _c.d);
      printf("hexadecimal floating point: %a\n", _c.d);
      printf("hexadecimal integer       : 0x%lx\n", _c.u);
      printf("binary                    : ");
      printf_d2b(_c);
      printf("\n");
    }
  else // others
    {
      printf("Bad type %s\n", type);
      printf("Expected float or double\n");
      return 1;
    }

  // You give good parameter
  return 0;
}
