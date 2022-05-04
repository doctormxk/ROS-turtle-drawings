#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/Pose.h>
#include "math.h"
#define PI 3.14
int main(int argc, char **argv)
{
	{//ros节点初始化
		ros::init(argc, argv, "velocity_publisher");
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
			vel_msg.request.x = ((16 * pow(sin(a), 3))) / 5 + 5.54;
			vel_msg.request.y = ((13 * cos(a) - 5 * cos(2 * a) - 2 * cos(3 * a) - cos(4 * a))) / 5 + 5.54;
			vel_msg.request.theta = PI / 2;
			turtle1_vel_pub.call(vel_msg);
			//这%%里也必须是2
			a = a + 0.0628;
			sleep(0.2);
		}
	}
	{
		ros::NodeHandle n;
		ros::service::waitForService("/turtle2/teleport_absolute");
		// %%这里必须是2
		ros::ServiceClient turtle2_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle2/teleport_absolute");
		turtlesim::TeleportAbsolute vel_msg;
		int i = 0;
		float a = 0;
		for (i = 0; i <= 100; i++)
		{
			vel_msg.request.y = ((16 * pow(sin(a), 3))) / 5 + 5.54;
			vel_msg.request.x = -((13 * cos(a) - 5 * cos(2 * a) - 2 * cos(3 * a) - cos(4 * a))) / 5 + 5.54;
			vel_msg.request.theta = PI;
			turtle2_vel_pub.call(vel_msg);

			//这%%里也必须是2
			a = a + 0.0628;
			sleep(0.2);
		}
	}
	{
		ros::NodeHandle n;
		ros::service::waitForService("/turtle3/teleport_absolute");
		// %%这里必须是2
		ros::ServiceClient turtle3_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle3/teleport_absolute");
		turtlesim::TeleportAbsolute vel_msg;
		int i = 0;
		float a = 0;
		for (i = 0; i <= 100; i++)
		{
			vel_msg.request.x = ((16 * pow(sin(a), 3))) / 5 + 5.54;
			vel_msg.request.y = -(13 * cos(a) - 5 * cos(2 * a) - 2 * cos(3 * a) - cos(4 * a)) / 5 + 5.54;
			vel_msg.request.theta = -PI / 2;
			turtle3_vel_pub.call(vel_msg);

			//这%%里也必须是2
			a = a + 0.0628;
			sleep(0.2);
		}
	}
	{
		ros::NodeHandle n;
		ros::service::waitForService("/turtle4/teleport_absolute");
		// %%这里必须是2
		ros::ServiceClient turtle4_vel_pub = n.serviceClient<turtlesim::TeleportAbsolute>("/turtle4/teleport_absolute");
		turtlesim::TeleportAbsolute vel_msg;
		int i = 0;
		float a = 0;
		for (i = 0; i <= 100; i++)
		{
			vel_msg.request.y = ((16 * pow(sin(a), 3))) / 5 + 5.54;
			vel_msg.request.x = (13 * cos(a) - 5 * cos(2 * a) - 2 * cos(3 * a) - cos(4 * a)) / 5 + 5.54;
			vel_msg.request.theta = 0;
			turtle4_vel_pub.call(vel_msg);

			//这%%里也必须是2
			a = a + 0.0628;
			sleep(0.2);
		}
	}
	return 0;
}



