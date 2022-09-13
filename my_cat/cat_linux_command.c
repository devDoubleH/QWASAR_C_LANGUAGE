#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 50
int main(int argc, char **argv)
{
  int   file;
  char  buffer[BUFFER_SIZE];
  int   read_size;

  if (argc < 2)
    {
      fprintf(stderr, "Error: usage: ./cat filename\n");
      return (-1);
    }
  file = open(argv[1], O_RDONLY);
  if (file == -1)
    {
      fprintf(stderr, "Error: %s: file not found\n", argv[1]);
      return (-1);
    }
  while ((read_size = read(file, buffer, BUFFER_SIZE)) > 0)
    write(1, &buffer, read_size);

  close(file);
  return (0);
}