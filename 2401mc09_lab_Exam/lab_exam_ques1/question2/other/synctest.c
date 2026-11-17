#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int i, k;
  char out[3];

  // error-path checks: silent unless something is wrong
  if(sem_wait(5) != -1 || sem_post(5) != -1 ||
     sem_init(8, 0) != -1 || sem_init(0, -1) != -1)
    printf(1, "error-check FAILED\n");

  sem_init(0, 1);
  sem_init(1, 0);
  sem_init(2, 0);

  for(i = 0; i < 3; i++){
    if(fork() == 0){
      out[0] = 'A' + i;
      out[1] = ' ';
      out[2] = 0;
      for(k = 0; k < 5; k++){
        sem_wait(i);                 // wait for my turn
        printf(1, "%s", out);
        sem_post((i + 1) % 3);       // hand the turn to the next letter
      }
      exit();
    }
  }
  for(i = 0; i < 3; i++)
    wait();
  printf(1, "\nDone\n");
  exit();
}
