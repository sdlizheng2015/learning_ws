/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-29 13:20:32
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-29 13:49:36
 * @FilePath: /learning_ws/src/learning_service/src/turtle_command_server.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

ros::Publisher turtle_vel_pub;
bool PubCommand = false;

bool CommandCallback(std_srvs::Trigger::Request &req,
                    std_srvs::Trigger::Response &res){
    PubCommand = !PubCommand;

    ROS_INFO("Publish turtle velocity command [%s]", PubCommand==true?"Yes":"No");

    res.success= true;
    res.message = "Change turtle command state!";

    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtle_command_server");
    ros::NodeHandle node;
    //创建一个名为/turtle_command的服务
    ros::ServiceServer command_service = node.advertiseService("/turtle_command", CommandCallback);
    turtle_vel_pub = node.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

    ROS_INFO("Ready to receive turtle command.");

    ros::Rate loop_rate(10);

    while(ros::ok()){
        ros::spinOnce();

        if(PubCommand){
            geometry_msgs::Twist vel_msg;
            vel_msg.linear.x = 0.5;
            vel_msg.angular.z = 0.2;
            turtle_vel_pub.publish(vel_msg);
        }
        loop_rate.sleep();
    }

    return 0;
}
