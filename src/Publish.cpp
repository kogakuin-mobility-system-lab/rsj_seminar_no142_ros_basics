#include <ros/ros.h>
#include <rsj_seminar_no142_ros_basics/Text.h>

#include <string>

int main(int argc, char **argv) {
  ros::init(argc, argv, "Publish");
  ros::NodeHandle node;

  std::string message;
  std::string date;
  ros::param::param<std::string>("~message", message, "test seminar 2022");
  ros::param::param<std::string>("~date", date, "September 10");

  ros::Publisher pub = node.advertise<rsj_seminar_no142_ros_basics::Text>("Publish", 1);

  ros::Rate rate(1);

  while (ros::ok()) {
    ros::spinOnce();

    ROS_INFO("Publishing message '%s %s'", message.c_str(), date.c_str());
    rsj_seminar_no142_ros_basics::Text sample;
    sample.message = message;
    sample.date = date;
    pub.publish(sample);

    rate.sleep();
  }

  return 0;
}
