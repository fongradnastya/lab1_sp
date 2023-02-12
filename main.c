#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

/*!
Создаёт новый дочерний поток методом fork-and-exec
\param[in] program программа для запуска в дочернем потоке
\param[in] argList[] список аргументов для запуска
\retun pid дочернего процесса
*/
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

/*!
Запускает основной процесс программы
\return код завершения программы
*/
int main()
{
  int childStatus;
  
  printf("------------------------------------------------------------------\n");
  printf("This program is workind with matrix and chainging its string order\n");
  printf("------------------------------------------------------------------\n");
  /* The argument list*/
  char* argList[] = {};

  /* Spawn a child process mmand. Ignore the returned child process id.  */
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
