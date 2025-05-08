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
    void topic_callback(const turtlesim::msg::Pose &msg) const
    {
        RCLCPP_INFO(this->get_logger(), "x: %.2f, y: %.2f, theta: %.2f", msg.x, msg.y, msg.theta);
    }
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtlePoseSubscriber>());
    rclcpp::shutdown();
    return 0;
}