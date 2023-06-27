#include <stdio.h>

int main(void)

{
  int a = 1, b = 2, c = 3;

  printf("%3d%3d%3d\n", a, b, c);

  {
    int b = 4;

    int c = 5;

    printf("%3d%3d%3d\n", a, b, c);

    a = b;

    {
      int c = 6;

      c = b;

      printf("%3d%3d%3d\n", a, b, c);
    }

    printf("%3d%3d%3d\n", a, b, c);

    { printf("%3d%3d%3d\n", a, b, c); }

    printf("%3d%3d%3d\n", a, b, c);
  }

  printf("%3d%3d%3d\n", a, b, c);

  return 0;
}
