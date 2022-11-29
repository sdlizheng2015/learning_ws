/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-29 16:56:10
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-29 18:40:39
 * @FilePath: /learning_ws/src/learning_tf/src/turtle_tf2_pub.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>

std::string turtle_name;

void DoPose(const turtlesim::Pose::ConstPtr& pose)
{
    static tf2_ros::TransformBroadcaster broadcaster;

    geometry_msgs::TransformStamped tfs;
    tfs.header.frame_id = "world";
    tfs.child_frame_id = turtle_name; 
    tfs.header.stamp = ros::Time::now();
    tfs.transform.translation.x = pose->x;
    tfs.transform.translation.y = pose->y;
    tfs.transform.translation.z = 0.0;
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();

    broadcaster.sendTransform(tfs);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "turtle_tf2_pub");
    if (argc != 2)
    {
        ROS_ERROR("agrv error!");
    }
    else
    {
        turtle_name = argv[1];
        ROS_INFO("pub %s pose start...", turtle_name.c_str());
    }

    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe<turtlesim::Pose>(turtle_name+"/pose",1000,&DoPose);
    ros::spin();
    return 0;
}
