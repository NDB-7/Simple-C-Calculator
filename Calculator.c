#include <stdio.h>
#include <stdlib.h>

int add(int num1, int num2) {
  return num1 + num2;
}

int sub(int num1, int num2) {
  return num1 - num2;
}

int mul(int num1, int num2) {
  return num1 * num2;
}

int divd(int num1, int num2) {
  return num1 / num2;
}


int main(void) {

  FILE *log = fopen("log.txt", "r");

  if (log == NULL) {
    log = fopen("log.txt", "w");
    fprintf(log, "Calculator Log:\n");
    fclose(log);
  }

  log = fopen("log.txt", "a");

  int (*operations[4])(int num1, int num2) = {add, sub, mul, divd};
  char operationsType[4] = {'+', '-', 'x', '/'};

  int num1, num2, operation;

  printf("Enter your first integer: ");
  scanf("%d", &num1);

  printf("Enter your second integer: ");
  scanf("%d", &num2);

  printf("\n0: Add\n1: Subtract\n2: Multiply\n3: Divide\n\nNow pick your operation (0-3): ");
  scanf("%d", &operation);

  int answer = operations[operation](num1, num2);

  printf("\nYour answer is %d!\n\n(Answer logged to log.txt)", answer);

  fprintf(log, "\n%d %c %d = %d", num1, operationsType[operation], num2, answer);

  fclose(log);

  return 0;

}