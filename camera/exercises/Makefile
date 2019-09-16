SHELL := /bin/bash

define run_docker
        docker run --rm -it -u $$(id -u):$$(id -g) -v $$(pwd):$$(pwd) -w $$(pwd) \
				   -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:rw --gpus=all \
				   carlosgalvezp/sfnd:latest $(1)
endef

.PHONY: clean
clean:
	rm -rf build

.PHONY: build
build:
	mkdir -p build
	$(call run_docker, /bin/bash -c 'cd build && cmake .. && make -j8')

.PHONY: create-matrix
create-matrix: build
	$(call run_docker, /bin/bash -c './build/OpenCV_exercises/create_matrix')

.PHONY: change-pixels
change-pixels: build
	$(call run_docker, /bin/bash -c './build/OpenCV_exercises/change_pixels')

.PHONY: load-image-1
load-image-1: build
	$(call run_docker, /bin/bash -c 'cd OpenCV_exercises/images && ../../build/OpenCV_exercises/load_image_1')

.PHONY: load-image-2
load-image-2: build
	$(call run_docker, /bin/bash -c 'cd OpenCV_exercises/images && ../../build/OpenCV_exercises/load_image_2')

.PHONY: load-image-3
load-image-3: build
	$(call run_docker, /bin/bash -c 'cd OpenCV_exercises/images && ../../build/OpenCV_exercises/load_image_3')

.PHONY: ttc-lidar
ttc-lidar: build
	$(call run_docker, /bin/bash -c 'cd TTC_lidar/dat && ../../build/TTC_lidar/compute_ttc_lidar')

.PHONY: ttc-camera
ttc-camera: build
	$(call run_docker, /bin/bash -c 'cd TTC_camera/dat && ../../build/TTC_camera/compute_ttc_camera')

.PHONY: gaussian-smoothing
gaussian-smoothing: build
	$(call run_docker, /bin/bash -c 'cd gradient_filtering/images && ../../build/gradient_filtering/gaussian_smoothing')

.PHONY: gradient-sobel
gradient-sobel: build
	$(call run_docker, /bin/bash -c 'cd gradient_filtering/images && ../../build/gradient_filtering/gradient_sobel')

.PHONY: magnitude-sobel
magnitude-sobel: build
	$(call run_docker, /bin/bash -c 'cd gradient_filtering/images && ../../build/gradient_filtering/magnitude_sobel')

.PHONY: cornerness-harris
cornerness-harris: build
	$(call run_docker, /bin/bash -c 'cd cornerness_harris/images && ../../build/cornerness_harris/cornerness_harris')

.PHONY: detect-keypoints
detect-keypoints: build
	$(call run_docker, /bin/bash -c 'cd detect_keypoints/images && ../../build/detect_keypoints/detect_keypoints')
