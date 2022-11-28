/*
 * @Author: lizh 447628890@qq.com
 * @Date: 2022-11-28 22:33:42
 * @LastEditors: lizh 447628890@qq.com
 * @LastEditTime: 2022-11-28 22:42:43
 * @FilePath: /learning_ws/src/learning_service/src/turtle_spawn.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by lizh 447628890@qq.com, All Rights Reserved. 
 */
#include <ros/ros.h>
#include <turtlesim/Spawn.h>

//客户端代码，请求/spawn服务，服务数据类型为turtlesim::Spawn
int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtle_spawn");
    ros::NodeHandle node;

    //发现/spawn服务后，创建一个客户端，连接名为/spawn的服务
    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");
    
    //初始化请求数据
    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle2";

    //请求调用
    ROS_INFO("Call service to spawn turtle[x:%0.2f, y:%0.2f, name:%s],",
                srv.request.x, srv.request.y, srv.request.name.c_str());
    add_turtle.call(srv);

    ROS_INFO("Spawn turtle successfully [name:%s]", srv.response.name.c_str());

    return 0;
}
