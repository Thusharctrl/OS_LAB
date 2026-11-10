#include <stdio.h>
#include <unistd.h>

int main()
{
    char sname[100];

    printf("Enter shell script name: ");
    scanf("%99s", sname);

    execl("/bin/sh", "sh", sname, (char *)NULL);

    perror("Error: cannot execute script");
    return 1;
}
