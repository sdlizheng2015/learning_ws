/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-29 16:56:10
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-29 18:56:55
 * @FilePath: /learning_ws/src/learning_tf/src/turtle_tf2_sub.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_ros/transform_listener.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "turtle_tf2_sub");
    ros::NodeHandle node;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Publisher pub = node.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 1000);
    
    ros::Rate rate(10);
    while(node.ok())
    {
        geometry_msgs::TransformStamped tfs;
        try
        {          
            tfs = buffer.lookupTransform("turtle2", "turtle1", ros::Time(0), ros::Duration(3.0));
            geometry_msgs::Twist twist;
            twist.linear.x = 0.5 * sqrt(pow(tfs.transform.translation.x, 2) + pow(tfs.transform.translation.y, 2));
            twist.angular.z = 4 * atan2(tfs.transform.translation.y, tfs.transform.translation.x);
        
            pub.publish(twist);
        }
        catch(const std::exception& e)
        {
            ROS_WARN("%s",e.what());
            ros::Duration(1.0).sleep();
            continue;
        }
        rate.sleep();
        ros::spinOnce;
    }
    return 0;
}
