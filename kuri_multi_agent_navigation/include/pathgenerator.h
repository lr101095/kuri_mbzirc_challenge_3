#ifndef PATH_GENERATOR_H
#define PATH_GENERATOR_H

#include "sspp/pathplanner.h"
#include "ros/ros.h"
#include <ros/package.h>
#include <tf/tf.h>
#include <tf_conversions/tf_eigen.h>
#include <geometry_msgs/Pose.h>
#include <eigen_conversions/eigen_msg.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include "sspp/distance_heuristic.h"
#include "sspp/rviz_drawing_tools.h"
#include "rviz_visual_tools/rviz_visual_tools.h"
//#include <mavros/mavros.h>
#include "geometry_msgs/PoseStamped.h"

#include <kuri_msgs/Tasks.h>
#include <kuri_msgs/NavTask.h>
#include <kuri_msgs/NavTasks.h>

#include <actionlib/server/simple_action_server.h>
#include <kuri_msgs/GeneratePathsAction.h>
#include <kuri_msgs/PickObjectAction.h>
#include <kuri_msgs/DropObjectAction.h>
#include "nav_msgs/Path.h"

class PathGenerator
{
public:
    geometry_msgs::Pose uav1_currentPose;
    geometry_msgs::Pose uav2_currentPose;
    geometry_msgs::Pose uav3_currentPose;
    std::vector<geometry_msgs::Pose> endPoses;
    geometry_msgs::Pose target_coord;
    kuri_msgs::Tasks tasks;
    ros::NodeHandle nh;
    ros::Publisher searchSpacePub;
    ros::Publisher connectionsPub;
    PathGenerator();
    void uav1_startPositionCallback(const geometry_msgs::PoseStamped& msg);
    void uav2_startPositionCallback(const geometry_msgs::PoseStamped& msg);
    void uav3_startPositionCallback(const geometry_msgs::PoseStamped& msg);
    void navTasksCallback(const kuri_msgs::Tasks newtasks);
    kuri_msgs::NavTasks generatePaths(const kuri_msgs::Tasks newtasks);
};
#endif // PATH_GENERATOR_H
