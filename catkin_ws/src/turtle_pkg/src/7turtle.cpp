/*
	创建第二只小乌龟
 */
 /*
	 创建第二只小乌龟
  */
#include "ros/ros.h"
#include "turtlesim/Spawn.h"
#include <turtlesim/Kill.h>
#define PI 3.1415926
int main(int argc, char *argv[])
{

	setlocale(LC_ALL, "");

	//执行初始化
	ros::init(argc, argv, "create_turtle");
	//创建节点
	ros::NodeHandle n;
	//创建服务客户端
	ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("/spawn");
	ros::ServiceClient client_kill = n.serviceClient<turtlesim::Kill>("kill");//定义一个/kill服务的客户端
	turtlesim::Kill kill_name;
	kill_name.request.name = "turtle1";
	client_kill.call(kill_name);//调用/kill服务杀死孤独的小乌龟
	ros::service::waitForService("/spawn");
	turtlesim::Spawn spawn;
	spawn.request.name = "turtle1";
	spawn.request.x = 7.54;
	spawn.request.y = 7.54;
	spawn.request.theta = 0;
	bool flag = client.call(spawn);
	spawn.request.name = "turtle2";
	spawn.request.x = 3.54;
	spawn.request.y = 7.54;
	spawn.request.theta = 0;
	bool flag2 = client.call(spawn);
	spawn.request.name = "turtle3";
	spawn.request.x = 6.54;
	spawn.request.y = 9.272;
	spawn.request.theta = 0;
	bool flag3 = client.call(spawn);
	spawn.request.name = "turtle4";
	spawn.request.x = 4.54;
	spawn.request.y = 9.272;
	spawn.request.theta = PI;
	bool flag4 = client.call(spawn);

	spawn.request.name = "turtle5";
	spawn.request.x = 6.54;
	spawn.request.y = 5.808;
	spawn.request.theta = 0;
	bool flag5 = client.call(spawn);
	spawn.request.name = "turtle6";
	spawn.request.x = 4.54;
	spawn.request.y = 5.808;
	spawn.request.theta = 0;
	bool flag6 = client.call(spawn);
	spawn.request.name = "turtle7";
	spawn.request.x = 5.54;
	spawn.request.y = 7.54;
	spawn.request.theta = 0;
	bool flag7 = client.call(spawn);
	
	ros::spin();

	return 0;
}
