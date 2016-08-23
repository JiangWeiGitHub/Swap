#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define COUNTER 100
#define MAXSIZE 1024*1024*256

int main(int argc, char** argv)
{
  int mb = 0;
  char* buffer;
  char* bufferAddress[COUNTER];

  struct timeval tval_before, tval_after, tval_result;

  for ( int i = 0; i < COUNTER; i++)
  {
    gettimeofday(&tval_before, NULL);

    buffer = (char *)malloc( MAXSIZE );

    gettimeofday(&tval_after, NULL);

    if ( buffer == NULL )
    {
      printf("Malloc Error!\n");
    }
    else
    {
      printf("Malloced the %d Memory!\n", i);
    }

    timersub(&tval_after, &tval_before, &tval_result);
    printf("Malloc Time elapsed: %ld.%06ld seconds.\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

    bufferAddress[i] = buffer;

    sleep(1);
  }

  while(1)
  {
    gettimeofday(&tval_before, NULL);

    memset(bufferAddress[mb], 0, MAXSIZE);

    gettimeofday(&tval_after, NULL);

    mb++;

    if ( mb == COUNTER - 1 )
    {
      mb = 0;
    }

    timersub(&tval_after, &tval_before, &tval_result);

    printf("Memset the %d Memory!\n", mb);
    printf("Memset Time elapsed: %ld.%06ld seconds.\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

    sleep(1);
  }

  return 0;
}
