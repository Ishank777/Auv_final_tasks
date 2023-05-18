#include<ros/ros.h>
#include<std_msgs/String.h>
// #include "pkg_1/custom.h"
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void cb(const std_msgs::String::ConstPtr& msg)
{
cout<<(msg->data.c_str())<<endl;
}

int main(int argc, char** argv)
{
ros::init(argc, argv, "Subscriber_1");

ros::NodeHandle nh_s1;

ros::Subscriber sub = nh_s1.subscribe("data1", 1000, cb);

ros::spin();

return 0;
}