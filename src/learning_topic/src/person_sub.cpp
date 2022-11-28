/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-28 22:16:50
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-28 22:26:58
 * @FilePath: /learning_ws/src/learning_topic/src/person_sub.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include "learning_topic/Person.h"

void PersonInfoCallback(const learning_topic::Person::ConstPtr& msg){
    ROS_INFO("Subscribe Person Info: name:%s , age:%d , sex:%d",
                msg->name.c_str(), msg->age, msg->sex);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "person_sub");
    ros::NodeHandle node;
    ros::Subscriber person_info_sub = node.subscribe("/person_info", 1, PersonInfoCallback);
    ros::spin();
    return 0;
}
