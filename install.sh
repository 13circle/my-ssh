#!/bin/bash

base_dir="~/.myssh"
script_dir="$base_dir/sshconnect"

mkdir $base_dir 2> /dev/null
mkdir $script_dir 2> /dev/null
rm -f $base_dir/myssh

git clone https://github.com/13circle/my-ssh $base_dir
gcc $base_dir/myssh.c -o $base_dir/myssh

if [ -z $(cat ~/.bashrc 2> /dev/null | grep myssh) ]; then
  echo "alias myssh='$base_dir/myssh'" >> ~/.bashrc
fi

