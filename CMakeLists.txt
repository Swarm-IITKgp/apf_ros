cmake_minimum_required(VERSION 2.8.3)
project(apf)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  roscpp
)

# generate_messages(
#   DEPENDENCIES
#   geometry_msgs
#)

catkin_package(
  CATKIN_DEPENDS geometry_msgs roscpp message_runtime
  INCLUDE_DIRS include
  LIBRARIES apf
)

include_directories(
  include/apf
  ${catkin_INCLUDE_DIRS}
)

add_library(apf src/c_map.cpp src/Field.cpp src/Filter_waypt.cpp src/simulate.cpp)


install(TARGETS apf
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})
install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})

add_executable(motion_planner src/motion_planner.cpp)
target_link_libraries(motion_planner ${catkin_LIBRARIES} apf)
add_dependencies(motion_planner apf_generate_messages_cpp)
