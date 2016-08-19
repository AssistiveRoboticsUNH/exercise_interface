Setup
=====
To run the interface you will need the following packages in the same catkin workspace:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- myo_raw - https://github.com/ylmeng/myo_raw  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- (optional) myo_nao - https://github.com/idkm23/myo_nao  
  
##### Envirnonment setup  
```
sudo apt-get install python-pip
pip install --upgrade pip
sudo pip install scipy  
sudo pip install sklearn  
sudo adduser <username> dialout 
sudo apt-get install ros-indigo-qt-build 
sudo apt-get install ros-indigo-pocketsphinx
sudo apt-get install gstreamer0.10-gconf
``` 

If you are completely new to ros, install rosindigo. Then, go to a directory you would like the project in and do:
```
mkdir myo
cd myo
mkdir src
cd src
catkin_init_workspace
git clone https://github.com/ylmeng/myo_raw.git
git clone https://github.com/idkm23/myo_nao.git        # DO NOT DO THIS IF YOU HAVE NOT CONFIGURED THE NAO ON YOUR SYSTEM
git clone https://github.com/idkm23/exercise_interface.git
cd ..
catkin_make
source devel/setup.bash
```

Now your project is configured properly and you may launch the interface with:  
```roslaunch exercise_interface interface.launch``` 

There is also a bash script which automatically launches exercise_interface with some configurations. Please refer to https://github.com/ylmeng/myo_raw/blob/master/scripts/launch.sh
If you have correctly installed the myo_raw package, you should find it under the 'script' folder in that package. Go to that directory to run the script. In the script you may need to replace 'wlan2' with another keyword (e.g. 'eth0') depending on how your network is set up. Use the command ```ifconfig``` to check the setup. Also replace ```source ~/myocp/myo/devel/setup.bash``` with the correct path. 
   
**If you want to use the Nao in the interface you must do:**  
```NAO_IP=10.0.3.16 roslaunch exercise_interface interface.launch using_nao:=true```  
(hit the button on the Nao's chest if you don't know its IP)  

To install the nao sdk and other basics see this tutorial:
http://wiki.ros.org/nao/Tutorials/Installation  
You will need to login and download something from here: https://community.aldebaran.com/ so contact Momotaz for this information.
Also install this repo, as the naoqi has changed so we have preserved our version:  
```git clone https://github.com/idkm23/naoqi.git```

How to use the training interface
===
- After you launch the interface, you should see a control panel. The speech recognition program will launch automatically. I suggest you test it first. The output can be seen in the terminal.
- Click "Launch Myo" to launch Myo armbands.
- On the Android device, launch the Exercise Learner program. You should be able to see a 3D model.
- Click "Calibrate Myo" for calibration. Then you may click "No Evaluation" to see how the 3D model tracks your arm.
- Click "Clear" to move the old ros bag files to a trash folder. 
- Click "Train Classifier" to start training, and the button caption will automatically become "Stop Training". Perform the exercise till the end. Whenever you reach a critical point of the exercise, say the word "tag".
- Click "Stop Training" to end training.
- If you are not satisfied with the training, click "Delete Last" to move the last ros bag to trash. Otherwise click "Train Classifier" again to perform the same task again, if you want to collect more data. I suggest you always calbirate Myo before training.
- After you collect all the data you want for the same task, click "Begin Trial" to build data. You will see a digram visualizing the data. Close it to proceed. At the end, the Android program will demonstrate the built task for you.
- You can click "Begin Practice" to try the prompting/evaluation program. Eventually a user will use this program, although from a different interface. Say "stop" when you finish practicing.
- If everything is ok, go to ```myo_raw/myo_mdp/data```. After you build data, some new files have been created here. Copy all the files to ```myo_raw/myo_mdp/data1``` if it is corresponding to "Task 1". Replace 1 with 2 or 3 for other task types. You do this for running the client interface.

Note
===
- You need to calibrate the Myo armbands about every 2 minutes. Use the "No Evaluation" button to see how your arm is tracked.
- The rosbags are saved in ```myo_raw/data/work```. When you build data, all rosbags in that folder will be regarded as the same task. Old rosbags can be found in ```myo_raw/data/work/bagTrash```
- Currently we are not using the file ```mdp.pkl```. It was generated for an older version of the program.
- Sometimes the speech recognition program fails to launch (10~20% chance). Just close the interface and start over again. It only recognize words in the vocabulary.


