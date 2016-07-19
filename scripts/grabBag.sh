#!/bin/bash
mkdir -p ../../../src/myo_raw/data/work/bagTrash
cd ../../../src/myo_raw/data/work
rosbag record /myo/l/emg /myo/u/emg /myo/l/imu /myo/u/imu /exercise/detected_state /myo/l/ort /myo/u/ort
