#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
int READLINE_READ_SIZE = 512;

void init_my_readline(){
  READLINE_READ_SIZE = 512;
}

char *my_readline(int fd){
  char *line = NULL;
  int number_alloc = 0;
  int l = 0;
  char m = 0;
  int readnumber = 0;
  for (l = 0; l < READLINE_READ_SIZE; l++){
    
    readnumber = read(fd, &m, 1);
    if (readnumber == 0){
      break;
    }
    if (readnumber == -1){

      break;
      printf("Error: read() failed in my_readline()\n");
    }

    if (number_alloc == 0){
      line = malloc(sizeof(char) * READLINE_READ_SIZE);
      if (line == NULL){

        printf("Error");
      }
      number_alloc = READLINE_READ_SIZE;
    }

    if (l == number_alloc - 1){
      line = realloc(line, sizeof(char) * (number_alloc + READLINE_READ_SIZE));
      if (line == NULL){

        printf("Error");
      }
      number_alloc += READLINE_READ_SIZE;
    }
    line[l] = m;
  }
  return line;
}

int main(int ac, char **av)
{
  char *str = NULL;

  int fd = open("./README.md", O_RDONLY);
  while ((str = my_readline(fd)) != NULL)
  {
      printf("%s\n", str);
      free(str);
  }
  close(fd);

  return 0;
}