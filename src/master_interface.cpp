#include "../include/master_interface.h"

// defines the functionality of the MasterInterface class

// Basic constructor for the MasterInterface. Sets up the
// ros objects and starts the ros
MasterInterface::MasterInterface(QMainWindow* parent) : QMainWindow(parent), uiComponents(new UIComponents()) {
    uiComponents->setupUi(this);
    ros::start();

    trialBegin_pub = n.advertise<std_msgs::Int32>("/exercise/begin_trial", 100);
    myoLaunch_pub = n.advertise<std_msgs::Int32>("/myo/launch", 100);
    myoCalibrate_pub = n.advertise<std_msgs::Int32>("/myo/calibrate", 100);
    exerciseMode_pub = n.advertise<std_msgs::Int32>("/exercise/mode", 100);
    
    // unallows the user to change the size of the window
    setFixedSize(size());
}

void MasterInterface::on_trainingRecord_clicked() {

    // This if-else block produces the toggle-like functionality of the button
    if(uiComponents->trainingRecord->text() != "stop training") {
        uiComponents->trainingRecord->setText("stop training");  
        uiComponents->trainingRecord->setDown(true); // makes the button look pressed
        
        // start training
        if(script_utils::getPIDbyName(script_utils::ROSBAG_PROCESS_NAME) != 0) {
            script_utils::startBagRecording();
        } else {
            ROS_INFO("already recording");
        }

    }  else {
        uiComponents->trainingRecord->setText("train");    
        uiComponents->trainingRecord->setDown(false);

        // stop training
        script_utils::killBagProcess();
    }
}

void MasterInterface::on_trainingClear_clicked() {
    script_utils::removeBags();
}

void MasterInterface::on_trainingDelete_clicked() {
    script_utils::removeLastBag();
}

// Signals to build a classifier & play a demonstration through ros
void MasterInterface::on_trialBegin_clicked() {
    std_msgs::Int32 msg;
    msg.data = 0;
    trialBegin_pub.publish(msg);

    exerciseMode_pub.publish(msg); 
}

// Signals to enter the practice mode (exercise evaluation & mimicking)
void MasterInterface::on_trialPractice_clicked() {
    std_msgs::Int32 msg;
    msg.data = 1;

    exerciseMode_pub.publish(msg);
}

// Signals to enter the practice mode with NO EVALUATION
void MasterInterface::on_trialSandbox_clicked() {
    std_msgs::Int32 msg;
    msg.data = 2;

    exerciseMode_pub.publish(msg);
}

// Signals to launch 1 or 2 myos depending on the value stored in the combo box
void MasterInterface::on_myoLaunch_clicked() {
    std_msgs::Int32 msg;
    msg.data = uiComponents->getMyoCount();
    myoLaunch_pub.publish(msg);
}

// Signals to reset the orientation component in the myo which is relative to north
void MasterInterface::on_myoCalibrate_clicked() {
    std_msgs::Int32 msg;
    msg.data = uiComponents->getMyoCount();
    myoCalibrate_pub.publish(msg);
}

// Signals to start the myo_nao program. You should typically try to run the Nao FIRST, because if you hit Begin practice -> launch Nao
// Then the rest of the system will be in practice, but the Nao will start in 'Trial'
void MasterInterface::on_naoLaunch_clicked() {
    std_msgs::Int32 msg;

    // This if-else produces the toggle-like functionality of the button by checking & changing the text of the button for every click
    if(uiComponents->naoLaunch->text() != "stop Nao") {
        uiComponents->naoLaunch->setText("stop Nao");  
        uiComponents->naoLaunch->setDown(true);
        
        msg.data = 3;
        exerciseMode_pub.publish(msg);

    }  else {
        uiComponents->naoLaunch->setText("launch Nao");    
        uiComponents->naoLaunch->setDown(false);
        
        msg.data = 4;
        exerciseMode_pub.publish(msg);
        
    }
}

MasterInterface::~MasterInterface() {
    delete uiComponents;
}
