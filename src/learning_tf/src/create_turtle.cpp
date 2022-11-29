/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-29 16:42:50
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-29 16:56:28
 * @FilePath: /learning_ws/src/learning_tf/src/create_turtle.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "create_turtle");
    ros::NodeHandle node;
    ros::ServiceClient client = node.serviceClient<turtlesim::Spawn>("/spawn");

    ros::service::waitForService("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 2.0;
    spawn.request.theta = 3.14;

    client.call(spawn);
    ROS_INFO("create %s successfully!", spawn.response.name.c_str());

    ros::spin();

    return 0;
}
