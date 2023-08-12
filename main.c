#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"


int main(int argv, char **argc) {
  char working[100];
  unsigned int position = 0;
  char *w = NULL;
  token t;
  token previous;
  previous.value[0] = 255;
  char *line = "100 FOR I = -0 to 100:PRINT I:NEXT I";
  w = line;
  read(&w,&t);
  while (t.type != INVALID && t.type !=EOL){
    dump_token(t);
    read(&w,&t);

    switch (t.type) {
    case INTEGER:
      break;
    case FLOAT:
      break;
    case STRING:
      break;
    case VAR:
      break;
    case OPERATOR:
        if (previous.type == OPERATOR || previous.value[0] == 255) {
            if ((t.value[0] == 2) && (previous.value[0] != 40)) {    //already checked for operator
                t.value[0] = NEGATE;
            }
            else {
                printf("Syntax Error");
            }
        }
        //fall through to default
    default:
      working[position++] = t.type;
      previous = t;
    }
    //convert to int, float. Transcribe strings to string area.
  }
  w=line;
  return 0;
}

