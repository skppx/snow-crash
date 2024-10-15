```sh
$: ls
level02.cpap
```

RESEARCH:   https://en.wikipedia.org/wiki/Pcap
            https://serverfault.com/questions/38626/how-can-i-read-pcap-files-in-a-friendly-format
            
COMMAND:    tcpdump -qns 0 -A -r level02.pcap | less

RESULT (truncated):
            wwwbugs login: 
            06:23:48.730579 IP 59.233.235.218.39247 > 59.233.235.223.12121: tcp 0
            E..4..@.@.J.;...;....O/Y.......L...s.......
            ...^..R}
            06:23:54.377030 IP 59.233.235.218.39247 > 59.233.235.223.12121: tcp 0
            E..4..@.@.J.;...;....O/Y.......L...s.......
            ......R}
            06:23:54.377594 IP 59.233.235.223.12121 > 59.233.235.218.39247: tcp 0
            E..4..@.@..k;...;.../Y.O...L...............
            ..X.....
            06:23:54.377802 IP 59.233.235.218.39247 > 59.233.235.223.12121: tcp 0
            E..4..@.@.J.;...;....O/Y.......M...s.......
            ......X.

**still not really readable but we can see a user trying to connect with login and password**

https://gitlab.com/wireshark/wireshark

**using wireshark to read all packet send from 59.233.235.218 (user)**

ip.src == 59.233.235.218  *filter in wireshark

**then we write all the character send by the user while being carefull about the delete**

PASSWORD: ft_waNDReL0L

then su flag02 and getflag

