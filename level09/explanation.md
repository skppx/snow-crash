in this level we have a program and a cipher

```sh
level09@SnowCrash:~$ cat token 
f4kmm6p|=�p�n��DB�Du{��
level09@SnowCrash:~$ ./level09 token 
tpmhr
level09@SnowCrash:~$ ./level09 abcdefg
acegikm
level09@SnowCrash:~$ ./level09 aaaaaaaaaaaaa
abcdefghijklm
```

with the last command we can see that the program add the index value to the ascii value for each char

```c
*str[i] = str[i] + i;*
```

so we need to code a program who can decipher the token (we assume that the token is already cypher because it has unprintable character)
*we get the token file with scp command*

```sh
scp -P 4242 level09@192.168.56.101:/home/user/level09/token /mnt/nfs/homes/phabets/post-common-core/snow-crash/level09
```

```c
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
```

RESULT: f3iji1ju5yuevaus41q1afiuq

then su flag09 and getflag

