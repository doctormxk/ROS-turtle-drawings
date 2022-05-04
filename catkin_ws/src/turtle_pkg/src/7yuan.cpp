#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/Pose.h>
#include "math.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void func1();
void func2();
void func3();
void func4();
void func5();
void func6();
void func7();
int main() {
	pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7;//进程号类型
	pid1 = fork();
	if (pid1 == 0) {
		func1();
	}
	else if (pid1 > 0)
	{
		pid2 = fork();
		if (pid2 == 0) func2();
		else if (pid2 > 0)
		{
			pid3 = fork();
			if (pid3 == 0) func3();
			else if (pid3 > 0)
			{
				pid4 = fork();
				if (pid4 == 0) func4();
				else if (pid4 > 0)
				{
					pid5 = fork();
					if (pid5 == 0) func5();
					else if (pid5 > 0)
					{
						pid6 = fork();
						if (pid6 == 0) func6();
						else if (pid6 > 0)
						{
							pid7 = fork();
							if (pid7 == 0) func7();
							else if (pid7 > 0)
							{
								waitpid(-1, NULL, 0);
							}
						}
					}
				}
			}
		}
	}
}
void func1()
{
	int argc;
	char **argv;
	//ros节点初始化
	ros::init(argc, argv, "velocity1_publisher");
	//创建节点句柄
	ros::NodeHandle n;
	ros::service::waitForService("/turtle1/teleport_absolute");
	// %%这里必须是2
	//创建一个publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist,队列长度10
	ros::ServiceClient turtle1_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
	//初始化geometry_msgs::Twist类型的消息
	turtlesim::TeleportAbsolute vel_msg;
	int i = 0;
	float a = 0;
	for (i = 0; i <= 100; i++)
	{
		vel_msg.request.x = 2 * sin(a) + 8.54;
		vel_msg.request.y = 2 * cos(a) + 5.54;

		turtle1_vel_pub.call(vel_msg);
		a = a + 0.0628;
		sleep(0.2);
	}
}
void func2()
{
	int argc;
	char **argv;
	//ros节点初始化
	ros::init(argc, argv, "velocity2_publisher");
	//创建节点句柄
	ros::NodeHandle n;
	ros::service::waitForService("/turtle2/teleport_absolute");
	// %%这里必须是2
	//创建一个publisher，发布名为/turtle2/cmd_vel的topic，消息类型为geometry_msgs::Twist,队列长度10
	ros::ServiceClient turtle2_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle2/teleport_absolute");
	//初始化geometry_msgs::Twist类型的消息
	turtlesim::TeleportAbsolute vel_msg;
	int i = 0;
	float a = 0;
	for (i = 0; i <= 100; i++)
	{
		vel_msg.request.x = 2 * sin(a) + 2.54;
		vel_msg.request.y = 2 * cos(a) + 5.54;

		turtle2_vel_pub.call(vel_msg);
		a = a + 0.0628;
		sleep(0.2);
	}
}
void func3()
{
	int argc;
	char **argv;
	//ros节点初始化
	ros::init(argc, argv, "velocity3_publisher");
	//创建节点句柄
	ros::NodeHandle n;
	ros::service::waitForService("/turtle3/teleport_absolute");
	// %%这里必须是2
	//创建一个publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist,队列长度10
	ros::ServiceClient turtle3_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle3/teleport_absolute");
	//初始化geometry_msgs::Twist类型的消息
	turtlesim::TeleportAbsolute vel_msg;
	int i = 0;
	float a = 0;
	for (i = 0; i <= 100; i++)
	{
		vel_msg.request.x = 2 * sin(a) + 6.84;
		vel_msg.request.y = 2 * cos(a) + 8.138;

		turtle3_vel_pub.call(vel_msg);
		a = a + 0.0628;
		sleep(0.2);
	}
}
void func4()
{
	int argc;
	char **argv;
	//ros节点初始化
	ros::init(argc, argv, "velocity4_publisher");
	//创建节点句柄
	ros::NodeHandle n;
	ros::service::waitForService("/turtle4/teleport_absolute");
	// %%这里必须是2
	//创建一个publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist,队列长度10
	ros::ServiceClient turtle4_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle4/teleport_absolute");
	//初始化geometry_msgs::Twist类型的消息
	turtlesim::TeleportAbsolute vel_msg;
	int i = 0;
	float a = 0;
	for (i = 0; i <= 100; i++)
	{
		vel_msg.request.x = 2 * sin(a) + 4.04;
		vel_msg.request.y = 2 * cos(a) + 8.138;

		turtle4_vel_pub.call(vel_msg);
		a = a + 0.0628;
		sleep(0.2);
	}
}
void func5()
{
	int argc;
	char **argv;
	//ros节点初始化
	ros::init(argc, argv, "velocity5_publisher");
	//创建节点句柄
	ros::NodeHandle n;
	ros::service::waitForService("/turtle5/teleport_absolute");
	// %%这里必须是2
	//创建一个publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist,队列长度10
	ros::ServiceClient turtle5_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle5/teleport_absolute");
	//初始化geometry_msgs::Twist类型的消息
	turtlesim::TeleportAbsolute vel_msg;
	int i = 0;
	float a = 0;
	for (i = 0; i <= 100; i++)
	{
		vel_msg.request.x = 2 * sin(a) + 6.84;
		vel_msg.request.y = 2 * cos(a) + 2.942;

		turtle5_vel_pub.call(vel_msg);
		a = a + 0.0628;
		sleep(0.2);
	}
}
void func6()
{
	int argc;
	char **argv;
	//ros节点初始化
	ros::init(argc, argv, "velocity6_publisher");
	//创建节点句柄
	ros::NodeHandle n;
	ros::service::waitForService("/turtle6/teleport_absolute");
	// %%这里必须是2
	//创建一个publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist,队列长度10
	ros::ServiceClient turtle6_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle6/teleport_absolute");
	//初始化geometry_msgs::Twist类型的消息
	turtlesim::TeleportAbsolute vel_msg;
	int i = 0;
	float a = 0;
	for (i = 0; i <= 100; i++)
	{
		vel_msg.request.x = 2 * sin(a) + 4.04;
		vel_msg.request.y = 2 * cos(a) + 2.942;

		turtle6_vel_pub.call(vel_msg);
		a = a + 0.0628;
		sleep(0.2);
	}
}
void func7()
{
	int argc;
	char **argv;
	//ros节点初始化
	ros::init(argc, argv, "velocity7_publisher");
	//创建节点句柄
	ros::NodeHandle n;
	ros::service::waitForService("/turtle7/teleport_absolute");
	// %%这里必须是2
	//创建一个publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist,队列长度10
	ros::ServiceClient turtle7_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle7/teleport_absolute");
	//初始化geometry_msgs::Twist类型的消息
	turtlesim::TeleportAbsolute vel_msg;
	int i = 0;
	float a = 0;
	for (i = 0; i <= 100; i++)
	{
		vel_msg.request.x = 2 * sin(a) + 5.54;
		vel_msg.request.y = 2 * cos(a) + 5.54;

		turtle7_vel_pub.call(vel_msg);
		a = a + 0.0628;
		sleep(0.2);
	}
}
