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
   
**If you want to use the Nao in the interface you must do:**  
```NAO_IP=10.0.3.16 roslaunch exercise_interface interface.launch using_nao:=true```  
(hit the button on the Nao's chest if you don't know its IP)  

To install the nao sdk and other basics see this tutorial:
http://wiki.ros.org/nao/Tutorials/Installation  
You will need to login and download something from here: https://community.aldebaran.com/ so contact Momotaz for this information.
Also install this repo, as the naoqi has changed so we have preserved our version:  
```git clone https://github.com/idkm23/naoqi.git```
