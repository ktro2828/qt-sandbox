#include "ros2_qt/img_viewer.hpp"

#include <QApplication>
#include <QPainter>

#include <sensor_msgs/image_encodings.hpp>

#include <cv_bridge/cv_bridge.h>

QtViewer::QtViewer(QWidget * parent) : QWidget(parent)
{
}

void QtViewer::renderImage(const cv::Mat & img)
{
  if (img.empty()) {
    return;
  }

  q_img_ = QImage(img.ptr(), img.cols, img.rows, img.step, QImage::Format_RGB888);
  update();
}

void QtViewer::paintEvent(QPaintEvent * e)
{
  Q_UNUSED(e);
  QPainter painter(this);
  if (q_img_.width() == 0 || q_img_.height() == 0) {
    return;
  }

  painter.drawImage(QPoint(0, 0), q_img_);
}

ViewerNode::ViewerNode() : rclcpp::Node("img_viewer")
{
  img_topic_ = declare_parameter<std::string>("img_topic");
  resize_ratio_ = declare_parameter<double>("resize_ratio", 0.5);

  sub_img_ = create_subscription<sensor_msgs::msg::CompressedImage>(
    img_topic_, 10, std::bind(&ViewerNode::callbackImage, this, std::placeholders::_1));

  window_.resize(640, 480);
  window_.setWindowTitle("Image Viewer");
  window_.show();
}

ViewerNode::ViewerNode(const rclcpp::NodeOptions & options) : rclcpp::Node("img_viewer", options)
{
  ViewerNode();
}

inline void ViewerNode::callbackImage(sensor_msgs::msg::CompressedImage::ConstSharedPtr img_msg)
{
  cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(img_msg, sensor_msgs::image_encodings::BGR8);
  } catch (cv_bridge::Exception & e) {
    RCLCPP_ERROR_STREAM(get_logger(), "cv bridge exception: " << e.what());
    return;
  }
  cv::resize(cv_ptr->image, cv_ptr->image, cv_ptr->image.size(), resize_ratio_, resize_ratio_);
  window_.renderImage(cv_ptr->image);
}

#include "img_viewer.moc"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  QApplication app(argc, argv);
  rclcpp::spin(std::make_shared<ViewerNode>());
  app.exec();
  rclcpp::shutdown();
}