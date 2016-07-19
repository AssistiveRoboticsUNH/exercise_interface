#ifndef SCRIPT_UTILS_H
#define SCRIPT_UTILS_H

#include <sys/types.h>
#include <signal.h>

// An ugly file. Runs scripts to collect and manage rosbags, however, it could all be done with C code.
// Uses the 'system' function to run bash scripts
namespace script_utils {

    const std::string ROSBAG_PROCESS_NAME = "/lib/rosbag/record --buffsize 256 --chunksize 768 /myo/l/emg /myo/u/emg /myo/l/imu /myo/u/imu";
    const std::string ROSBAG_RECORD_LOC = "../../../src/exercise_interface/scripts/grabBag.sh &";
    const std::string ROSBAG_CLEAR_LOC = "../../../src/exercise_interface/scripts/removeBags.sh &";
    const std::string ROSBAG_REMOVELAST_LOC = "../../../src/exercise_interface/scripts/removeLastBag.sh &";
    const std::string KILL_RECORD_NODE = "../../../src/exercise_interface/scripts/killRecordNode.sh &";

    inline int startBagRecording() {
        system(ROSBAG_RECORD_LOC.c_str());
    }

    // finds the process id of any process that contains 'p_name'
    inline int getPIDbyName(const std::string p_name) {
        char buf[512];

        std::string s = "pgrep -f \'" + p_name + "\'";
        FILE *cmd_pipe = popen(s.c_str(), "r");
        ROS_INFO(s.c_str());


        fgets(buf, 512, cmd_pipe);
        pid_t pid = strtoul(buf, NULL, 10);

        pclose( cmd_pipe );

        return pid;
    }

    // This searches for the rosbag process that is currently recording. 
    // CAUTION: It will kill ANY process whose name contains the string: 'ROSBAG_PROCESS_NAME'
    // So if you're trying to rosbag something yourself while the interface is running, you may accidently kill the wrong recording
    inline void killBagProcess() {
        pid_t rosbag_pid = getPIDbyName(ROSBAG_PROCESS_NAME);
        kill(rosbag_pid, SIGINT);
        system(KILL_RECORD_NODE.c_str());
    }

    inline void removeBags() {
        system(ROSBAG_CLEAR_LOC.c_str());
    }

    // sorts by recency and deletes the most recent bag incase of an poorly recorded trial
    inline void removeLastBag() {
        system(ROSBAG_REMOVELAST_LOC.c_str());
    }
}

#endif
