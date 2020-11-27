/*************************************************************************
	> File Name: turtle_spawn.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月09日 星期一 15时17分29秒
 ************************************************************************/

#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtle_spawn");

    ros::NodeHandle node;

    ros::service::waitForService("/spawn");//jaming function like wait();
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle2";

    ROS_INFO("Call service to spawn turtle[x:%0.6f, y:%0.6f, name:%s]",
             srv.request.x, srv.request.y, srv.request.name.c_str());

    add_turtle.call(srv); //ask for service with data(package) named srv

    ROS_INFO("Spwan turtle successfully [name:%s]", srv.response.name.c_str());

    return 0;
}
