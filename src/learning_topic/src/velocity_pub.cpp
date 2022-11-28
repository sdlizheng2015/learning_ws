/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-28 14:41:19
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-28 20:51:20
 * @FilePath: /learning_ws/src/learning_topic/src/velocity_pub.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{   
    //节点初始化,第3个参数为rosnode list显示的节点名称 
    ros::init(argc, argv, "turtle_vel_pub");
    //实例化节点类
    ros::NodeHandle node;
    //创建publisher，node.advertise<消息类型>("话题名称"，消息队列长度)
    ros::Publisher turtle_vel_pub = node.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
    //设置循环频率，参数单位为Hz
    ros::Rate loop_rate(10);

    int count = 0;

    while(ros::ok()){
        //初始化geometry_msgs::Twist
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.2;

        //发布消息
        turtle_vel_pub.publish(vel_msg);
        ROS_INFO("Publish turtle velocity command[%0.3f m/s, %0.3f rad/s]",
                    vel_msg.linear.x, vel_msg.angular.z);

        loop_rate.sleep();
    }

    return 0;
}
