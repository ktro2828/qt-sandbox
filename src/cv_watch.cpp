#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <chrono>
#include <ctime>
#include <iostream>

int main()
{
  cv::Mat image(920, 1080, CV_8UC3);

  cv::namedWindow("Clock", cv::WINDOW_AUTOSIZE);

  while (true) {
    // clear image in black
    image.setTo(cv::Scalar(0, 0, 0));

    // get current time
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto milliseconds =
      std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000;
    std::tm * localTime = std::localtime(&time);
    std::string timeString = std::to_string(localTime->tm_hour) + ":" +
                             std::to_string(localTime->tm_min) + ":" +
                             std::to_string(localTime->tm_sec) + "." + std::to_string(milliseconds);

    // display time on window
    cv::putText(
      image, timeString, cv::Point(100, 300), cv::FONT_HERSHEY_SIMPLEX, 13.0, cv::Scalar(0, 0, 255),
      2);
    cv::imshow("Clock", image);

    // break out if `Esc` is pressed
    if (cv::waitKey(1) == 27) {
      break;
    }
  }

  cv::destroyAllWindows();

  return 0;
}