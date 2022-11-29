/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-29 15:15:47
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-29 15:30:52
 * @FilePath: /learning_ws/src/learning_tf/src/turtle_tf_broadcaster.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

std::string turtle_name;

void PoseCallback(const turtlesim::PoseConstPtr& msg)
{
    //创建tf广播器
    static tf::TransformBroadcaster br;

    //初始化tf数据
    tf::Transform transform;
    transform.setOrigin(tf::Vector3(msg->x, msg->y, 0.0));
    tf::Quaternion q;
    q.setRPY(0, 0, msg->theta);
    transform.setRotation(q);

    //广播
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_tf_broadcaster");

    if(argc != 2)
    {
        ROS_ERROR("need turtle name as argument");
        return -1;
    }

    turtle_name = argv[1];

    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe(turtle_name+"/pose", 10, &PoseCallback);
    ros::spin();

    return 0;
}