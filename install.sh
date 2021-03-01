#!/bin/bash

shellrc_name=.${SHELL##*/}rc
shellrc=$HOME/$shellrc_name

base_dir="$HOME/.myssh"

mkdir $base_dir 2> /dev/null
mkdir "$base_dir/sshconnect" 2> /dev/null
mkdir "$base_dir/sshconnect/keys" 2> /dev/null
mkdir "$base_dir/sshconnect/configs" 2> /dev/null

rm -rf "$base_dir/src"
git clone https://github.com/13circle/my-ssh "$base_dir/src"
gcc "$base_dir/src/myssh.c" -o "$base_dir/src/myssh"

if [ -z "$(cat $shellrc 2> /dev/null | grep myssh)" ]; then
  echo "" >> $shellrc
  echo "# Inserted by MySSH" >> $shellrc
  echo "export MYSSH_ROOT_DIR=$base_dir" >> $shellrc
  echo "alias myssh='$base_dir/src/myssh'" >> $shellrc
  echo "" >> $shellrc

  echo "Now restart the shell or run 'source ~/$shellrc_name'"
fi

