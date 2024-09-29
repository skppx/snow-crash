```sh
$: find / -user flag00 | less
/usr/sbin/john
/rofs/usr/sbin/john
```

"find / -user flag00" : find all file from user flag00
"less" : for not display error message


```sh
$: cat /usr/sbin/john
cdiiddwpgswtgt       # cypher pasword
```

find the encryption type with dCode website : https://www.dcode.fr/identification-chiffrement

the cipher is encrypted with "affine cipher" : https://en.wikipedia.org/wiki/Affine_cipher

decode it with dCode website : https://www.dcode.fr/chiffre-affine

KEY : a = 1 ; b = 15

RESULT : nottoohardhere

log in flag00 user with the decrypted password : su flag00

then use getflag command to get the token for level01
