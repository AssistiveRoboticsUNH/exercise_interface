#ifndef MASTER_INTERFACE_H
#define MASTER_INTERFACE_H

#include <string>

#include <ros/ros.h>
#include <rosbag/bag.h>
#include <std_msgs/Int32.h>

#include <QMainWindow>
#include <QWidget>
#include <QTimer>

#include "ui_components.h"
#include "script_utils.h"

// The main window of the interface using QT. All onClick functionality is handled here
// When the ui is clicked, typically a rosmessage is sent out to trigger the other
// components of the project
class MasterInterface : public QMainWindow
{
  Q_OBJECT
public:
  explicit MasterInterface(QMainWindow* parent = 0);
  ~MasterInterface();

private:
  ros::NodeHandle n;

  // These publishers are used to communicate to the other project components when a button is pressed
  ros::Publisher myoLaunch_pub, myoCalibrate_pub, trialBegin_pub, exerciseMode_pub;

  // All gui components are defined and accessible through *uiComponents
  UIComponents *uiComponents;

// These functions are called when their corresponding button is pressed
// to link a button to a function, see: ui_components.h
private Q_SLOTS:  
  void on_trainingRecord_clicked();
  void on_trainingDelete_clicked();
  void on_trainingClear_clicked();

  void on_trialBegin_clicked();
  void on_trialPractice_clicked();
  void on_trialSandbox_clicked();

  void on_myoLaunch_clicked();
  void on_myoCalibrate_clicked();
  void on_naoLaunch_clicked();
};
#endif
