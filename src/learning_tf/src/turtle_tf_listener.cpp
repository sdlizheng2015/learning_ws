/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-29 15:26:59
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-29 15:46:27
 * @FilePath: /learning_ws/src/learning_tf/src/turtle_tf_listener.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <turtlesim/Pose.h>
#include <turtlesim/Spawn.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_tf_listener");
    ros::NodeHandle node;

    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn srv;
    add_turtle.call(srv);

    ros::Publisher turtle_vel = node.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

    tf::TransformListener listener;

    ros::Rate rate(10);

    while(node.ok())
    {
        tf::StampedTransform transform;
        try
        {
            listener.waitForTransform("/turtle2", "/turtle1", ros::Time(0), ros::Duration(3.0));
            listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);
        }
        catch(tf::TransformException& ex)
        {
            ROS_ERROR("%s", ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(), transform.getOrigin().x());
        vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) + pow(transform.getOrigin().y(), 2));
        turtle_vel.publish(vel_msg);
        rate.sleep();
    }
    return 0;
}
