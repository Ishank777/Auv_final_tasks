#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <string>
#include <string_view> //for starts_with
using namespace std;

string user;
int starts_with_user(const std::string &str)
{
    int length = user.size();
    string u = str.substr(0, length);
    if (u == user)
        return 1;
    else
        return 0;
}

void cb(const std_msgs::String::ConstPtr &msg)
{
    // cout << user << " : " << (msg->data.c_str()) << endl;
    // if(msg.starts_with(user))
    string u = msg->data.c_str();
    if (starts_with_user(msg->data))
        return;
    cout << (msg->data) << endl<< "-> ";
}

/*
 user -

*/

bool getline_async(std::string &str, std::istream &is, char delim = '\n')
{

    static std::string lineSoFar;
    char inChar;
    int charsRead = 0;
    bool lineRead = false;
    str = "";
    do
    {
        charsRead = is.readsome(&inChar, 1);
        if (charsRead >= 1)
        {
            if (inChar == delim)
            {
                str = lineSoFar;
                lineSoFar = "";
                lineRead = true;
            }
            else
            {
                lineSoFar.append(1, inChar);
            }
        }
    } while (charsRead != 0 && !lineRead);

    return lineRead;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);

    string name;
    cout << "Enter the name for the node : ";
    getline(cin, name);
    user = name;
    string sender = name;

    ros::init(argc, argv, name);

    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("data1", 1000, cb);
    ros::Publisher pub = nh.advertise<std_msgs::String>("data1", 1000);

    ros::Rate loop_rate(10);
    cout << "Node has been initialised\n";
    cout << "-> ";

    while (ros::ok())
    {
        std_msgs::String msg;
        string message = "";
        bool lineRead = getline_async(message, std::cin);
        if (lineRead == true)
        {
            cout << "-> ";

            msg.data = user + " : " + message;
            pub.publish(msg);
        }

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

// bool getline_async(std::string& str, std::istream& is, char delim = '\n')
// {
//     static std::string lineSoFar;
//     char inChar;
//     int charsRead = 0;
//     bool lineRead = false;
//     str = "";
//     cout<<"Enter your message : ";

//     do {
//         cin>>inChar;
//         charsRead = is.readsome(&inChar, 1);
//         if (charsRead == 1)
//         {
//             cout<<"1----------\n";
//             if (inChar == delim)
//             {
//                 str = lineSoFar;
//                 lineSoFar = "";
//                 lineRead = true;
//             }
//             else
//             {
//                 cout<<"2----------\n";
//                 lineSoFar.append(1, inChar);
//             }
//         }
//     } while (charsRead != 0 && !lineRead);

//     return lineRead;
// }