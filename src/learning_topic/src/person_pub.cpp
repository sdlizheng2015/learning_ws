/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-28 21:59:11
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-28 22:28:12
 * @FilePath: /learning_ws/src/learning_topic/src/person_pub.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include "learning_topic/Person.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "person_pub");
    ros::NodeHandle node;
    ros::Publisher person_info_pub = node.advertise<learning_topic::Person>("/person_info", 1);
    ros::Rate loop_rate(1);
    
    int count = 0;
    while (ros::ok()){
        learning_topic::Person person_msg;
        person_msg.name = "mm";
        person_msg.age = 18;
        person_msg.sex = learning_topic::Person::female;

        person_info_pub.publish(person_msg);
        ROS_INFO("Publish Person Info: name:%s , age:%d , sex:%d",
                    person_msg.name.c_str(), person_msg.age, person_msg.sex);
        loop_rate.sleep();
    }
    
    return 0;
}
