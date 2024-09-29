# Solution

Once we logged in, we see in the home folder a binary name level13, when we execute that binary we get this message:

```sh
level13@SnowCrash:~$ ./level13 
UID 2013 started us but we we expect 4242
```

So the binary ask for a specific UID since we meet this UID a quick look into /etc/passwd will give us the information,
that no user with this UID exist we need to reverse the program we will use decompile explorer.

Decompile explorer will provide us a good information one that you have a function with a looking flag as parameter:

```c
uVar2 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
```

If we take a quick look at that function we can see that this function actually decrypt the string parameter and will give you,
the real flag the line under in main will give us that confirmation.

```c
uVar2 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
printf("your token is %s\n",uVar2);
```

So from this we will take the generated C code from the decompiler hidra modify it compile it and run the program.

Here the modified generated C code function from the decompiler to generate the flag:

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *ft_reverse(char *str)
{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  unsigned char bVar5;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  bVar5 = 0;
  pcVar2 = strdup(str);
  local_1c = 0;
  local_20 = 0;
  do {
    uVar3 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + (uint)bVar5 * -2 + 1;
    } while (cVar1 != '\0');
    if (~uVar3 - 1 <= local_20) {
      return pcVar2;
    }
    if (local_1c == 6) {
      local_1c = 0;
    }
    if ((local_20 & 1) == 0) {
      if ((local_20 & 1) == 0) {
        for (local_14 = 0; local_14 < "0123456"[local_1c]; local_14 = local_14 + 1) {
          pcVar2[local_20] = pcVar2[local_20] + -1;
          if (pcVar2[local_20] == '\x1f') {
            pcVar2[local_20] = '~';
          }
        }
      }
    }
    else {
      for (local_18 = 0; local_18 < "0123456"[local_1c]; local_18 = local_18 + 1) {
        pcVar2[local_20] = pcVar2[local_20] + '\x01';
        if (pcVar2[local_20] == '\x7f') {
          pcVar2[local_20] = ' ';
        }
      }
    }
    local_20 = local_20 + 1;
    local_1c = local_1c + 1;
  } while( 1 );
}

int main(void) 
{
    char *str = ft_reverse("boe]!ai0FB@.:|L6l@A?>qJ}I");
    printf("%s\n", str);
    return (0);
}
```

The result once this is compiled and launch will be this:

```sh
level13@SnowCrash~: ./tmp/a.out
2A31L79asukciNyi8uppkEuSx
```

And now we can logged in level14.
