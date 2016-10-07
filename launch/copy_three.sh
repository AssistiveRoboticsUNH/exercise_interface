#!/bin/bash
cp  ~/ros_ws/src/myo_raw/myo_mdp/data/* ~/ros_ws/src/myo_raw/myo_mdp/data3/
touch ~/ros_ws/src/myo_raw/myo_mdp/data3/mdp.pkl
date >> ~/ros_ws/src/myo_raw/myo_mdp/data3/mdp.pkl
