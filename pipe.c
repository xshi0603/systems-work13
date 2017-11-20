#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

  int fds[2];
  pipe(fds);
  
  int fds2[2];
  pipe(fds2);

  int READ = 0;
  int WRITE = 1;
  
  if (fork() == 0) {
    // Child process
    // reading number
    close(fds[WRITE]);
    int *i;
    read(fds[READ], i, sizeof(i));

    // sending back number
    close(fds2[READ]);
    int i2 = i * 5;
    write(fds2[WRITE], &i2, sizeof(i2));
  } else {
    // Parent process
    // writing to child
    close(fds[READ]);
    int *i;
    &i = 15;
    write(fds[WRITE], &i, sizeof(i));

    // reading new number
    close(fds2[WRITE]);
    int i2;
    read(fds2[READ], i2, sizeof(i2));
    printf("parent received: [%d]\n", i2);
  }
  
}
