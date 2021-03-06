//this program is for requesting service named /show_person, service data type: learning_service::Person

#include <ros/ros.h>
#include "learning_service/Person.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "person_client");
    ros::NodeHandle node;

    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client = node.serviceClient<learning_service::Person>("/show_person");

    learning_service::Person srv;
    srv.request.name = "Tom";
    srv.request.age = 20;
    srv.request.sex = learning_service::Person::Request::male;

    ROS_INFO("Call service to show person[name:%s, age:%d, sex:%d]",
                srv.request.name.c_str(), srv.request.age, srv.request.sex);
    
    person_client.call(srv); //jaming function.

    ROS_INFO("Show person result: %s", srv.response.result.c_str());

    //make a comment here for testing the git function
    return 0;
}

