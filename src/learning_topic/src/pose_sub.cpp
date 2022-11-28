/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-28 21:16:21
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-28 21:38:55
 * @FilePath: /learning_ws/src/learning_topic/src/pose_sub.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include "turtlesim/Pose.h"

void PoseCallback(const turtlesim::Pose::ConstPtr& msg){
    ROS_INFO("Turtle Pose: x:%0.2f, y:%0.2f", msg->x, msg->y);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtle_pose_sub");
    ros::NodeHandle node;
    ros::Subscriber pose_sub = node.subscribe("/turtle1/pose", 10, PoseCallback);
    ros::spin();

    return 0;
}
