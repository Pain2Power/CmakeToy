## Proj 1

### Title

센서 데이터 구독 및 출력

### Content

/turtle1/pose를 구독해 위치와 방향을 콘솔에 출력

### Version

ros2 humble (~2027)

### Result

build

```bash
proj1$ colcon build
```

/turtle1/pose type and data type in turtlesim

```bash
proj1$ ros2 interface show turtlesim/msg/Pose

float32 x
float32 y
float32 theta
float32 linear_velocity
float32 angular_velocity
```

start subscriber for /turtle1/pose
```bash
proj1$ source install/setup.bash
proj1$ ros2 run proj1 turtle_pose_listen
```

start turtlesim node
```bash
$ ros2 run turtlesim turtlesim_node
```