#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Joy

tag = -1
labels = ['tag', 'home', 'task one', 'task two', 'task three', 'stop', 'help']


def callback(data):
    global tag
    if data.buttons[0] == 1:
        tag = 0
    elif data.buttons[1] == 1:
        tag = 1
    elif data.buttons[3] == 1:
        tag = 2
    elif data.buttons[2] == 1:
        tag = 3
    elif data.buttons[4] == 1:
        tag = 4
    elif data.buttons[5] == 1:
        tag = 5
    elif data.buttons[6] == 1:
        tag = 6


def tagger():
    global tag
    pub = rospy.Publisher('/recognizer/output', String, queue_size=1)
    lis = rospy.Subscriber('/joy', Joy, callback)
    rospy.init_node('tagger', anonymous=True)
    r = rospy.Rate(10)
    while not rospy.is_shutdown():
        if tag >= 0:
            rospy.loginfo(labels[tag])
            pub.publish(labels[tag])
            tag = -1
            r.sleep()
        r.sleep()

if __name__ == '__main__':
    try:
        tagger()
    except rospy.ROSInterruptException:
        pass
