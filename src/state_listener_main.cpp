#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <string>

const std::string TAGWORD("tag");
const std::string STOPWORD("stop");
const std::string HELPWORD("help");
ros::Publisher detected_state_pub;
ros::Publisher stop_trial_pub;

void isKeyword(std_msgs::String msg) {
    
    std_msgs::String keyword;
    
    if(msg.data == TAGWORD) {
        keyword.data = "tag";
    }
    
    if(msg.data == STOPWORD) {
        keyword.data = "stop";
    }
    
    if(msg.data == HELPWORD) {
        keyword.data = "help";
    }
    
    detected_state_pub.publish(keyword);
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "state_listener"); 
    ros::NodeHandle n;

    detected_state_pub = n.advertise<std_msgs::String>("/exercise/detected_state", 1000);
    ros::Subscriber sphinx_sub = n.subscribe("/recognizer/output", 1000, isKeyword);

    ros::spin();

    return 0;
}
