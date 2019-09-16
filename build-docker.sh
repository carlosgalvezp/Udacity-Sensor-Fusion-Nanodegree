#!/usr/bin/env bash
set -euxo pipefail

DOCKER_BUILDKIT=1 \
docker build --tag carlosgalvezp/sfnd:latest tools/docker
