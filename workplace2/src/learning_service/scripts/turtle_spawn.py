# !/usr/bin/env python
# _*_ coding: utf-8 _*_

import sys
import rospy
from turtlesim.srv import Spawn

def turtle_spawn():
    rospy.init_node('turtle_spawn')

    rospy.wait_for_service('/spawn')
    try:
        add_turtle = rospy.ServiceProxy('/spawn', Spawn)

        response = add_turtle(2.0, 2.0, 0.0, "turtle2")
        return response.name
    except rospy.ServiceException,e:
        print "Service call failed: %s"%e

if _name_ == "_main_":
    print "Spwan turtle successfully [name:%s]" %(turtle_spawn())
