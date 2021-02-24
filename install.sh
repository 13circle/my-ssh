#!/bin/bash

shellrc_name=.${SHELL##*/}rc
shellrc=$HOME/$shellrc_name

base_dir="$HOME/.myssh"
src_dir="$base_dir/src"
script_dir="$base_dir/sshconnect"

mkdir $base_dir 2> /dev/null
mkdir $script_dir 2> /dev/null

rm -rf $src_dir
git clone https://github.com/13circle/my-ssh $src_dir
gcc $src_dir/myssh.c -o $src_dir/myssh

if [ -z "$(cat $shellrc 2> /dev/null | grep myssh)" ]; then
  echo "" >> $shellrc
  echo "alias myssh='$src_dir/myssh'  # Inserted by MySSH" >> $shellrc
  echo "" >> $shellrc

  echo "Now restart the shell or run 'source ~/$shellrc_name'"
fi

