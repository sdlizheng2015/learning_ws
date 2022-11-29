/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-29 13:56:07
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-29 14:04:14
 * @FilePath: /learning_ws/src/learning_service/src/person_server.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include "learning_service/Person.h"

bool PersonCallback(learning_service::Person::Request &req,
                    learning_service::Person::Response &res)
{
    ROS_INFO("Person: name:%s age:%d sex:%d", req.name.c_str(), req.age, req.sex);
    res.result = "OK";
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "person_server");
    ros::NodeHandle node;
    ros::ServiceServer person_service = node.advertiseService("/show_person", PersonCallback);
    ROS_INFO("Ready to show person info.");
    ros::spin();
    return 0;
}
