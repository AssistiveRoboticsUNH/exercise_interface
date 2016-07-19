#!/bin/bash
mkdir -p ../../../src/myo_raw/data/work/bagTrash
cd ../../../src/myo_raw/data/work
fn=$(ls -t | grep ".bag" | head -n1)
mv -f -- "$fn" "bagTrash"
