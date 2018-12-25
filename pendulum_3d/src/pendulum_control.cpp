#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "example1_a");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::Float64>("/pendulum_3d/control_x_controller/command", 5);
  ros::Rate loop_rate(10);
  //double msg_=0.5;
  //n.param("msg",msg_,0.5);
  std_msgs::Float64 cmdvel;
  cmdvel.data = 0.5;
  while (ros::ok())
  {
    //ROS_INFO("%s", msg.data.c_str());
    pub.publish(cmdvel);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
