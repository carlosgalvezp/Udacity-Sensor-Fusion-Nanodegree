#include <iostream>
#include <numeric>
#include <array>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void gaussianSmoothing1()
{
    // load image from file
    cv::Mat img = cv::imread("../images/img1gray.png");

    // create filter kernel
    constexpr std::size_t kernel_size = 5U;
    constexpr std::size_t kernel_elements = kernel_size * kernel_size;
    std::array<float, kernel_elements> gauss_kernel =
    {
        1.0F,  4.0F,  7.0F,  4.0F, 1.0F,
        4.0F, 16.0F, 26.0F, 16.0F, 4.0F,
        7.0F, 26.0F, 41.0F, 26.0F, 7.0F,
        4.0F, 16.0F, 26.0F, 16.0F, 4.0F,
        1.0F,  4.0F,  7.0F,  4.0F, 1.0F
    };

    const float kernel_sum = std::accumulate(gauss_kernel.begin(), gauss_kernel.end(), 0.0F);
    for (float& kernel_element : gauss_kernel)
    {
        kernel_element /= kernel_sum;
    }

    cv::Mat kernel(kernel_size, kernel_size, CV_32F, gauss_kernel.data());

    // apply filter
    cv::Mat result(img.rows, img.cols, img.type());
    const int ddepth = -1;
    const cv::Point anchor = cv::Point(-1, -1);
    const double delta = 0.0;
    const int border_type = cv::BORDER_DEFAULT;
    cv::filter2D(img, result, ddepth, kernel, anchor, delta, border_type);

    // show result
    string windowName = "Gaussian Blurring";
    cv::namedWindow(windowName, 1); // create window
    cv::imshow(windowName, result);
    cv::waitKey(0); // wait for keyboard input before continuing
}

int main()
{
    gaussianSmoothing1();
}
