#include<ros/ros.h>
#include<std_msgs/String.h>
// #include "pkg_1/custom.h"
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
ros::init(argc, argv, "Publisher_2");
ros::NodeHandle nh_p2;
ros::Publisher pub = nh_p2.advertise<std_msgs::String>("data2", 1000);
ros::Rate loop_rate(10);
cout<<"Node has been initialised\n";

while(ros::ok())
{
std_msgs::String msg;
string message;
cout<<"Ready to take input\n";
getline(cin, message);
cout<<"\" " << message << " \"" << " will be sent\n";
msg.data = message;
// msg.name = message;
// msg.number = "number";
pub.publish(msg);
ros::spinOnce();
loop_rate.sleep();
}
return 0;
}

