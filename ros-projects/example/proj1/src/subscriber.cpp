#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include <turtlesim/msg/pose.hpp>

using std::placeholders::_1;

// Sub topic name : /turtle1/pose, topic type : turtlesim/msg/Pose

class Subscriber : public rclcpp::Node
{
public:
    Subscriber()
        : Node("proj1_subscriber")
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        subscriber_ = this->create_subscription<turtlesim::msg::Pose>(
            "/turtle1/pose",
            qos_profile,
            std::bind(&Subscriber::subscribe_topic_message, this, _1));
    }

private:
    void subscribe_topic_message(const std_msgs::msg::String::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "Received message: '%s'", msg->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Subscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
