#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 80
char buffer[BUFFER_SIZE];

int main(int argc, char *argv[])
{
  int fd = STDIN_FILENO;

  if (argc > 1)
  {
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
      char no_file[] = "No such file or directory\n";
      write(STDERR_FILENO, no_file, sizeof(no_file));
      exit(EXIT_FAILURE);
    }
  }
  ssize_t bytes_read;
  while ((bytes_read = read(STDIN_FILENO, buffer, 80)))
  {
    write(STDOUT_FILENO, buffer, bytes_read);
  }
  close(fd);
  return 0;
}
