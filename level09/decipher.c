#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    ssize_t len;
    char buf[26];
    int fd = open("token", O_RDONLY);
    len = read(fd, buf, 25);
    for (int i = 0; i < 26; i++)
    
        buf[i] = buf[i] - i;
    printf("%li, %s, %i\n", len, buf, fd);
    return (0);
}



