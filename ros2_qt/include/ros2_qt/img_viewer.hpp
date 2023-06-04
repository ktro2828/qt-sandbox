#ifndef IMG_VIEWER_HPP_
#define IMG_VIEWER_HPP_

#include <QImage>
#include <QWidget>
#include <opencv2/opencv.hpp>
#include <rclcpp/rclcpp.hpp>

#include <sensor_msgs/msg/compressed_image.hpp>

class QtViewer : public QWidget
{
  Q_OBJECT
public:
  QtViewer(QWidget * parent = nullptr);
  virtual ~QtViewer(){};

public slots:
  void renderImage(const cv::Mat & img);

protected:
  void paintEvent(QPaintEvent * e);

private:
  QImage q_img_;
};  // class QtViewer

class ViewerNode : public rclcpp::Node
{
public:
  ViewerNode();
  explicit ViewerNode(const rclcpp::NodeOptions & options);

private:
  std::string img_topic_;
  double resize_ratio_;
  QtViewer window_;

  rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr sub_img_;

  inline void callbackImage(sensor_msgs::msg::CompressedImage::ConstSharedPtr img_msg);
};

#endif  // IMG_VIEWER_HPP_