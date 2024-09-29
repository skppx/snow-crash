#!/bin/bash

touch /var/tmp/valid_file

while true
do
    ln -sf /var/tmp/valid_file /var/tmp/fake
    ln -sf /home/user/level10/token /var/tmp/fake
done
