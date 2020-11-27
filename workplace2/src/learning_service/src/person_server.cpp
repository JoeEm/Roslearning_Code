#include <ros/ros.h>
#include "learning_service/Person.h"


bool personCallback(learning_service::Person::Request &req, 
                    learning_service::Person::Response &res)
{
    ROS_INFO("Person: name:%s  age:%d  sex:%d", req.name.c_str(), req.age, req.sex);

    res.result = "OK";

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "person_serviver");
    ros::NodeHandle n;
    //establishing a server name '/show_person'
    ros::ServiceServer person_servive = n.advertiseService("/show_person", personCallback);


    ROS_INFO("Ready to show person information.");

    ros::spin(); //the process won't stop unless get killed

    return 0;
}