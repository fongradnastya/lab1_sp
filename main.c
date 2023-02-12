#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>


int spawn(char* program, char* argList[])
{
  pid_t childPid;

  /* Duplicate this process.  */
  childPid = fork();
  if (0 != childPid)
  {
    /* This is the parent process.  */
    return childPid;
  }
  else
  {
    /* Now execute PROGRAM, searching for it in the path. */
    execv(program, argList);

    /* The execvp function returns only if an error occurs.  */
    fprintf(stderr, "an error occurred in execv\n");
    abort();
  }
}

int main()
{
  int childStatus;
  
  /* The argument list to pass to the "ls" command.  */
  char* argList[] = {};

  /* Spawn a child process running the "ls" command.  Ignore the
     returned child process id.  */
  spawn("./child", argList);

  /* Wait for child process  */
  wait(&childStatus);
  if(WIFEXITED(childStatus))
  {
    printf("The child process exited normally with code %d.\n"
           , WEXITSTATUS(childStatus)
          );
  }
  else
  {
    printf("The child process exited abnormally.\n");
  }
  return 0;
}
