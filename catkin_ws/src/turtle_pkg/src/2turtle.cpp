/*
	创建第二只小乌龟
 */
#include "ros/ros.h"
#include "turtlesim/Spawn.h"
#include <turtlesim/Kill.h>
int main(int argc, char *argv[])
{
	
	setlocale(LC_ALL, "");

	//执行初始化
	ros::init(argc, argv, "create_turtle");
	//创建节点
	ros::NodeHandle nh;
	//创建服务客户端
	ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
	ros::ServiceClient client_kill = nh.serviceClient<turtlesim::Kill>("kill");//定义一个/kill服务的客户端
	turtlesim::Kill kill_name;
	kill_name.request.name = "turtle1";
	client_kill.call(kill_name);//调用/kill服务杀死孤独的小乌龟
	ros::service::waitForService("/spawn");
	turtlesim::Spawn spawn;
	spawn.request.name = "turtle2";
	spawn.request.x = 5.54;
	spawn.request.y = 6.54;
	spawn.request.theta = 0;
	bool flag = client.call(spawn);
	if (flag)
	{
		ROS_INFO("乌龟%s创建成功!", spawn.response.name.c_str());
	}
	else
	{
		ROS_INFO("乌龟2创建失败!");
	}

	ros::spin();

	return 0;
}
