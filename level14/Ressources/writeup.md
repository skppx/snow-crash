# Solution

When we logged in level14 you will find nothing no binary, no service that run, actually nothing.
But since the begining of this project i notice something multiple time when checking if my symlink where actually working for /bin/getflag,
here let me show you:

```sh
level14@SnowCrash:~$ cat /bin/getflag
...
$ÐUfЋu[]Ð[o[0123456You should not reverse thisLD_PRELOADInjection Linked lib detected exit..
/etc/ld.so.preload/proc/self/maps/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..
libcldCheck flag.Here is your token : You are root are you that dumb ?
I`fA>_88eEd:=`85h0D8HE>,D7`4Ci4=^d=J,?>i;6,7d416,7<>B16\AD<C6,G_<1>^7ci>l4BB8b:6,3fj7:,;bh>D@>8i:6@D?4d@:,C>8C60G>8:h:Gb4?l,AG8H.6,=4k5J0<cd/D@>>B:>:4H8B8h_20B4J43><8>\ED<;j@378H:J4<4<9i_I4k0J^5>B1j`9bci`mC{)jxkn<"uD~6%g7FK`7Dc6m~;}f8Cj#xFkel;#&ycfbK74H9D^3ed7k05445J0E4e;Da470hCi,E44Df[A4B/J@3f<=:`D8_Dw"4#?+3i]q&;p6 gtw88ECboe]!ai0FB@.:|L6l@A?>qJ}Ig <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|
Nope there is no token here for you sorry. Try again :)00000000 00:00 0LD_PRELOAD detected through memory maps exit ....
...
```

This is a `cat` of /bin/getflag have you notice this little message for us here let me show you this with `strings` command: 

```sh
level14@SnowCrash:~$ strings /bin/getflag
...
0123456                                                                                                                                                                                                                                                                      
You should not reverse this                                                                                                                                                                                                                                                  
LD_PRELOAD                                                                                                                                                                                                                                                                   
Injection Linked lib detected exit..                                                                                                                                                                                                                                         
/etc/ld.so.preload                                                                                                                                                                                                                                                           
/proc/self/maps                                                                                                                                                                                                                                                              
/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..                                                                                                                                                                                                        
libc                                                                                                                                                                                                                                                                         
Check flag.Here is your token :                                                                                                                                                                                                                                              
You are root are you that dumb ?
...
```

So apparently they dont want you to reverse why ? Let's find out (also you have multiple security added to avoid any interference with LD_PRELOAD or injecting wrong lib),
so this is some part of the main function:

```c
  if ( ptrace(PTRACE_TRACEME, 0, 1, 0) < 0 )
  {
    puts("You should not reverse this");
    return 1;
  }
  if ( getenv("LD_PRELOAD") || open("/etc/ld.so.preload", 0) > 0 )
  {
    fwrite("Injection Linked lib detected exit..\n", 1u, 0x25u, stderr);
    return 1;
  }
  v30 = syscall_open("/proc/self/maps", 0);
  if ( v30 == -1 )
  {
    fwrite("/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n", 1u, 0x46u, stderr);
    return 1;
  }
  do
  {
    do
    {
      while ( 1 )
      {
        if ( !syscall_gets((int)v31, 256, v30) )
          return 0;
        if ( !isLib(v31, (int)"libc") )
          break;
        v29 = 1;
      }
    }
    while ( !v29 );
    if ( isLib(v31, (int)"ld") )
    {
      fwrite("Check flag.Here is your token : ", 1u, 0x20u, stdout);
      v4 = getuid();
      if ( v4 == 3006 )
      {
        v15 = stdout;
        v16 = ft_des("H8B8h_20B4J43><8>\\ED<;j@3");
        fputs(v16, v15);
        goto LABEL_49;
      }
      if ( v4 > 0xBBE )
      {
        if ( v4 == 3010 )
        {
          v19 = stdout;
          v20 = ft_des("74H9D^3ed7k05445J0E4e;Da4");
          fputs(v20, v19);
          goto LABEL_49;
        }
        if ( v4 > 0xBC2 )
        {
          if ( v4 == 3012 )
          {
            v23 = stdout;
            v24 = ft_des("8_Dw\"4#?+3i]q&;p6 gtw88EC");
            fputs(v24, v23);
          }
          else if ( v4 < 0xBC4 )
          {
            v21 = stdout;
            v22 = ft_des("70hCi,E44Df[A4B/J@3f<=:`D");
            fputs(v22, v21);
          }
          else if ( v4 == 3013 )
          {
            v25 = stdout;
            v26 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
            fputs(v26, v25);
          }
          else
          {
            if ( v4 != 3014 )
              goto LABEL_48;
            v27 = stdout;
            v28 = ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
            fputs(v28, v27);
          }
          goto LABEL_49;
        }
        if ( v4 == 3008 )
        {
          v17 = stdout;
          v18 = ft_des("bci`mC{)jxkn<\"uD~6%g7FK`7");
          fputs(v18, v17);
          goto LABEL_49;
        }
        v11 = stdout;
        if ( v4 > 0xBC0 )
          v12 = ft_des("Dc6m~;}f8Cj#xFkel;#&ycfbK");
        else
          v12 = ft_des("78H:J4<4<9i_I4k0J^5>B1j`9");
      }
      else
      {
        if ( v4 == 3002 )
        {
          v9 = stdout;
          v10 = ft_des("<>B16\\AD<C6,G_<1>^7ci>l4B");
          fputs(v10, v9);
          goto LABEL_49;
        }
        if ( v4 <= 0xBBA )
        {
          if ( v4 == 3000 )
          {
            v5 = stdout;
            v6 = ft_des("I`fA>_88eEd:=`85h0D8HE>,D");
            fputs(v6, v5);
          }
          else if ( v4 > 0xBB8 )
          {
            v7 = stdout;
            v8 = ft_des("7`4Ci4=^d=J,?>i;6,7d416,7");
            fputs(v8, v7);
          }
          else
          {
            if ( v4 )
            {
LABEL_48:
              fwrite("\nNope there is no token here for you sorry. Try again :)", 1u, 0x38u, stdout);
              goto LABEL_49;
            }
            fwrite("You are root are you that dumb ?\n", 1u, 0x21u, stdout);
          }
LABEL_49:
          fputc(10, stdout);
          return 0;
        }
        if ( v4 == 3004 )
        {
          v13 = stdout;
          v14 = ft_des("?4d@:,C>8C60G>8:h:Gb4?l,A");
          fputs(v14, v13);
          goto LABEL_49;
        }
        v11 = stdout;
        if ( v4 > 0xBBC )
          v12 = ft_des("G8H.6,=4k5J0<cd/D@>>B:>:4");
        else
          v12 = ft_des("B8b:6,3fj7:,;bh>D@>8i:6@D");
      }
      fputs(v12, v11);
      goto LABEL_49;
    }
  }
  while ( afterSubstr(v31, (int)"00000000 00:00 0") );
  fwrite("LD_PRELOAD detected through memory maps exit ..\n", 1u, 0x30u, stderr);
  return 0;
```


As you can see we find that ft_des is also used same as the previous level, but also we can see that they check for a specific UID,
which is stored in the variable v4 to authorize the output of the flag:

```c
v4 = getuid();
if ( v4 == 3006 )
{
    v15 = stdout;
    v16 = ft_des("H8B8h_20B4J43><8>\\ED<;j@3");
    fputs(v16, v15);
    goto LABEL_49;
}
```

So to find the proper flag for level14 we need to find the proper uid first which is 3014 we can find this information just by using cat,
on the /etc/passwd here:

```sh
level14@SnowCrash:~$ cat /etc/passwd
...
flag14:x:3014:3014::/home/flag/flag14:/bin/bash
...
```

after the x you have the uid and guid of the user flag14, so back to the decompile code we are able to find the value that we want here:
```c
else
{
    if ( v4 != 3014 )
        goto LABEL_48;
    v27 = stdout;
    v28 = ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
    fputs(v28, v27);
}
goto LABEL_49;
```

so now we take the parameter of the ft_des function use our compiled version of that function we the same string as parameter and here is the result:
```sh
level14@SnowCrash:~$ ./tmp/a.out
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
```

To be sure that work we should be able to connect to flag14 user.

```sh
level14@SnowCrash:~$ su flag14
Password: 
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
flag14@SnowCrash:~$ getflag
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
flag14@SnowCrash:~$
```

And that's the end of snowcrash. 
