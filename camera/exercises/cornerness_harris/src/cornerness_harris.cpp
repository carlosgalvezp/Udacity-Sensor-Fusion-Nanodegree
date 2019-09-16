#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

using namespace std;

void cornernessHarris()
{
    // load image from file
    cv::Mat img;
    img = cv::imread("../images/img1.png");
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY); // convert to grayscale

    // Detector parameters
    int blockSize = 2;     // for every pixel, a blockSize × blockSize neighborhood is considered
    int apertureSize = 3;  // aperture parameter for Sobel operator (must be odd)
    int minResponse = 100; // minimum value for a corner in the 8bit scaled response matrix
    double k = 0.04;       // Harris parameter (see equation for details)

    // Detect Harris corners and normalize output
    cv::Mat dst, dst_norm, dst_norm_scaled;
    dst = cv::Mat::zeros(img.size(), CV_32FC1);
    cv::cornerHarris(img, dst, blockSize, apertureSize, k, cv::BORDER_DEFAULT);
    cv::normalize(dst, dst_norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
    cv::convertScaleAbs(dst_norm, dst_norm_scaled);

    // visualize results
    string windowName = "Harris Corner Detector Response Matrix";
    cv::namedWindow(windowName, 4);
    cv::imshow(windowName, dst_norm_scaled);
    cv::waitKey(0);

    // TODO: Your task is to locate local maxima in the Harris response matrix
    // and perform a non-maximum suppression (NMS) in a local neighborhood around
    // each maximum. The resulting coordinates shall be stored in a list of keypoints
    // of the type `vector<cv::KeyPoint>`.
    std::vector<cv::KeyPoint> keypoints;
    const float max_overlap = 0.0;
    for (int i = 0; i < dst_norm.rows; ++i)
    {
        for (int j = 0; j < dst_norm.cols; ++j)
        {
            // See if prominent corner
            if (dst_norm.at<float>(i, j) > static_cast<float>(minResponse))
            {
                // Create keypoint
                cv::KeyPoint keypoint;
                keypoint.pt = cv::Point2f(j, i);
                keypoint.size = static_cast<float>(2 * apertureSize);
                keypoint.response = dst_norm.at<float>(i, j);

                bool should_add_keypoint = true;

                // Run NMS around local neighborhood
                for (cv::KeyPoint& existing_keypoint : keypoints)
                {
                    if (cv::KeyPoint::overlap(keypoint, existing_keypoint))
                    {
                        if (keypoint.response > existing_keypoint.response)
                        {
                            // Replace existing keypoint if new keypoint in neighborhood has larger response
                            existing_keypoint = keypoint;
                        }
                        should_add_keypoint = false;  // Either replaced or ignored
                    }
                }

                if (should_add_keypoint)
                {
                    keypoints.push_back(keypoint);
                }
            }
        }
    }

    // Visualize
    windowName = "Harris Corner Detection Results";
    cv::namedWindow(windowName, 5);
    cv::Mat visImage = dst_norm_scaled.clone();
    cv::drawKeypoints(dst_norm_scaled, keypoints, visImage, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    cv::imshow(windowName, visImage);
    cv::waitKey(0);
}

int main()
{
    cornernessHarris();
}
