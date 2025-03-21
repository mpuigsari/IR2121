# IR2121 - Mobile Robotics

This repository showcases a series of simulation-based and real-world localization, mapping, and navigation experiments developed during the **IR2121 - Mobile Robotics** course, part of the 3rd year in the **Bachelor’s Degree in Robotic Intelligence** at Universitat Jaume I.

The course focuses on **autonomous navigation** for mobile robots, covering key robotics concepts such as SLAM, localization, sensor integration, and navigation stack setup using **ROS2** and simulators like **Webots** and **RViz**.

---

## 🚀 Summary of Projects

### 📦 Rosbag Recording and Visualization
- Manual teleoperation of a TurtleBot3 in both:
  - A **real indoor environment** (faculty building)
  - A **simulated house** in Webots
- Data recorded via **rosbag** and visualized using **rqt** and **RViz**

### 📍 Localization with Nav2
- Used **RViz Navigation2 (Nav2)** stack for:
  - Localizing the TurtleBot in pre-built maps (real and simulated)
  - Understanding costmaps, AMCL configuration, and robot poses

### 🗺️ SLAM (Simultaneous Localization and Mapping)
- Generated 2D maps using SLAM:
  - **Webots simulated environment** (house map)
  - **Custom map** recorded in the faculty
- Integrated SLAM toolchains into the ROS2 pipeline

### 🧭 Autonomous Navigation Project
- Final project focused on:
  - Publishing goals to the **Nav2 action server**
  - Monitoring navigation status and implementing stopping conditions
  - Working with **TF2** for robot pose tracking and transformation

---

## 🛠️ Technologies Used

- **ROS2 (Foxy/Humble)**
- **Webots**
- **RViz2**
- **rqt tools**
- **rosbag2**
- **Nav2 (Navigation2)**
- **TF2 (Transform Library)**

---

## 📚 Learning Outcomes

- Implementation of **2D autonomous navigation**
- Integration of **SLAM and localization** methods in simulation and real-world settings
- Hands-on experience with **robot teleoperation**, **sensor-based mapping**, and **goal-directed behaviors**
- Proficiency in **ROS2 ecosystem**, from topic publishing to advanced navigation control

---

## 📘 References

Course supported by:
- *A Concise Introduction to Robot Programming with ROS2* – Martín-Rico (CRC Press, 2023)
- *Introduction to Autonomous Mobile Robots* – Siegwart et al. (MIT Press, 2011)

---

## 👨‍🏫 Instructor

- Enric Cervera Mateu [![GitHub](https://img.shields.io/badge/GitHub-ecervera-black?logo=github)](https://github.com/ecervera)

---

