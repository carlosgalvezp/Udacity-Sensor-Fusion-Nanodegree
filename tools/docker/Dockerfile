FROM nvidia/opengl:1.0-glvnd-devel-ubuntu18.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    apt-get install --assume-yes --no-install-recommends \
        build-essential \
        cmake \
        libpcl-dev  && \
    rm -rf /var/lib/apt/lists/*
