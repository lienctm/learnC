// Description : expr function evaluates
// a reverse Polish notion from command line

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXVAL 100   // maximum depth of val stack

int sp;              // next avaiable position in array
char val[MAXVAL];

void push(double f) {
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error : stack full\n") ;
}

double pop(void) {
  if(sp > 0)
    return val[--sp];
  else
    printf("error : stack empty\n");
  return 0;
}


int main(int argc, char *argv[]) {
  int i;
  char *s;           // s is a pointer to the 1st element of argument
  int type;         // type can be a number or operator
  float a, b;

  for(i = 1; i < argc; i++) {
    s = argv[i] ;   // s is a pointer to the 1st element of argument[i]
    type = isdigit(s[0]) ? '0' : s[0];
    switch(type)   {
      case '0' :
        push(atof(s));
        break;

      case '+' :
        a = pop() ; b = pop();
        push(b + a);
        break;

      case '-' :
        a = pop() ; b = pop();
        push(b - a);
        break;

      case '*' :
        a = pop() ; b = pop();
        push(b * a);
        break;

      case '/' :
        a = pop() ; b = pop();
        push(b / a);
        break;

      default :
        printf("error : unknown command %c %s\n",type, s) ;
    }
  }
  printf("result : %.2f\n", pop());
}
