#!/bin/bash

NODE=`rosnode list | grep record`
if [[ "" !=  "$NODE" ]]; then
  echo "killing rosbag node"
  rosnode kill $NODE
fi
