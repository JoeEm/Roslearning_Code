//this demo: create a message_type which publish topic called turtle1/cmd_vel
//

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>


int main(int argc, char **argv)
{
	//Init ROS node
	ros::init(argc, argv, "velocity_publisher");
	
	// create node's handler
	ros::NodeHandle n;

	//create a Publisher which publishes the '/turtle1/cmd_vel' topic and message_type is geometry_msgs::Twist with queue length 10.
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

	//set loop frequency
	ros::Rate loop_rate(10);

	int count = 0;
	while (ros::ok())
	{
		//init the message geometry_msgs::Twist
		geometry_msgs::Twist vel_msg;
		vel_msg.linear.x = 0.5;
		vel_msg.angular.z = 0.2;
		
		//publish messages
		turtle_vel_pub.publish(vel_msg);
		ROS_INFO("Publish turtle velocity command[%0.2f m/s, %0.2f rad/s]",
           vel_msg.linear.x, vel_msg.angular.z);

        // set the delay-time-span according to the loop frequency
        loop_rate.sleep();
    }
    return 0;
}

