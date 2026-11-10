#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, fsize;
    char fname[100], buffer[1001];

    printf("Enter filename: ");
    scanf("%99s", fname);

    fd = open(fname, O_RDONLY);

    if(fd == -1)
    {
        printf("File not found\n");
        return 1;
    }

    fsize = read(fd, buffer, sizeof(buffer));

    if(fsize == -1)
        printf("Error reading file\n");
    else
    {
        buffer[fsize] = '\0';
        printf("File contents:\n%s", buffer);
    }

    close(fd);
    return 0;
}
