#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "bmath.h"

int main(int argv, char **argc) {
  char working[100];
  unsigned int position = 0;
  char *w = NULL;
  token t;
  token previous;
  previous.value[0] = 255;
  int wi=0;
  int *wip= NULL;
  float wf =0;
  float *wfp = NULL;
  t_string_info *ws;
  char *line = "100 FOR I = -0 to 100:PRINT \"Hello world\":NEXT I";
  w = line;
  read(&w,&t);
  while (t.type != INVALID && t.type !=EOL){
    dump_token(t);
    read(&w,&t);

    switch (t.type) {
    case INTEGER:
        wi = read_int(t.value);
        working[position++] = INT_TOKEN;
        wip = (int *)&working[position];
        *wip = wi;
        position = position + INT_SIZE;

        //printf("%d",wi);
      break;
    case FLOAT:
        wf = read_single(t.value);
        working[position++] = SING_TOKEN;
        wfp = (float *)&working[position];
        *wfp = wf;
        position = position + SINGLE_SIZE;
        //printf("%f",wf);
      break;
    case STRING:
        ws = (t_string_info *)t.value;
        working[position++]=STR_TOKEN;
        working[position++]=ws->length;
        for (int a =0; a < ws->length;a++) {
            working[position++] = *(ws->start++);
        }
      break;
    case SYMBOL:
    case ARRAY:
        if (t.type = SYMBOL)
            working[position++] = VAR_TOKEN;
        else
            working[position++] = ARRAY_TOKEN;
        wi = 0;
        //VARIABLE NAMES ARE > 128
        while (t.value[wi] != '\0' && t.value[wi] <128 && wi < MAX_TOKEN_LENGTH){
            working[position++] = t.value[wi++] | 0x80;
        }
      break;
    case OPERATOR:
        if (previous.type == OPERATOR || previous.value[0] == 255) {
            if ((t.value[0] == MINUS) && (previous.value[0] != 40)) {    //already checked for operator
                t.value[0] = NEGATE;
            }
            else {
                printf("Syntax Error");
            }
        }
        //fall through to default

    default:
      working[position++] = t.value[0];

    }
    //convert to int, float. Transcribe strings to string area.
    previous = t;
  }
  w=line;
  return 0;
}

