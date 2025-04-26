#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// turtlesim/msg/Pose
#include "turtlesim/msg/pose.hpp"

using std::placeholders::_1;

class TurtlePoseSubscriber : public rclcpp::Node
{
public:
    TurtlePoseSubscriber()
        : Node("tutle_pose_subscriber")
    {
        subscription_ = this->create_subscription<turtlesim::msg::Pose>(
            "turtle1/pose", 10, std::bind(&TurtlePoseSubscriber::topic_callback, this, _1));
    }

private:
    void topic_callback(const std_msgs::msg::String &msg) const
    {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}