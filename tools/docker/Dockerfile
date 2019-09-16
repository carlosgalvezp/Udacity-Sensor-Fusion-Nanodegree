FROM nvidia/opengl:1.0-glvnd-devel-ubuntu18.04

ENV DEBIAN_FRONTEND=noninteractive

# Basic build tools and PCL
RUN apt-get update && \
    apt-get install --assume-yes --no-install-recommends \
        build-essential \
        cmake \
        libpcl-dev  && \
    rm -rf /var/lib/apt/lists/*

# Opencv
# Install OpenCV dependencies
# https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html
# Libraries not installed (not available on Ubuntu 18.04):
# -libjasper-dev (optional)
RUN apt-get update && \
    apt-get install --assume-yes --no-install-recommends \
        ca-certificates \
        git \
        libavcodec-dev \
        libavformat-dev \
        libdc1394-22-dev \
        libgtk2.0-dev \
        libjpeg-dev \
        libpng-dev \
        libswscale-dev \
        libtbb2 \
        libtbb-dev \
        libtiff-dev \
        pkg-config \
        python-dev \
        python-numpy && \
    rm -rf /var/lib/apt/lists/*

# Install OpenCV
ENV CV_VERSION=4.1.1
RUN git clone https://github.com/opencv/opencv.git && \
    git clone https://github.com/opencv/opencv_contrib.git && \
    cd opencv_contrib && \
    git checkout ${CV_VERSION} && \
    cd ../opencv && \
    git checkout ${CV_VERSION} && \
    mkdir build && \
    cd build && \
    cmake -D CMAKE_BUILD_TYPE=Release \
          -D CMAKE_INSTALL_PREFIX=/usr/local \
          -D OPENCV_ENABLE_NONFREE=ON \
          -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
          -D BUILD_EXAMPLES=OFF \
          -D BUILD_TESTS=OFF \
          -D BUILD_DOCS=OFF \
          -D WITH_EIGEN=OFF \
          ..  && \
    make -j8 && \
    make install && \
    cd ../.. && \
    rm -rf opencv opencv_contrib
