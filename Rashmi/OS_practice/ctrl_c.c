#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void fun(int sig)
{
    printf("FUN! - I got signal %d\n", sig);
   (void) signal(SIGINT, SIG_DFL);  //reinitialization of signal handler
}

/*  The main function has to intercept the SIGINT signal generated when we type Ctrl-C .
    For the rest of the time, it just sits in an infinite loop,
    printing a message once a second.  */

int main()
{
   (void) signal(SIGINT, fun); // user defiend signal handler initialization

    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
}
