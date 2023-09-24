#!/bin/bash
sudo docker build -t krypto_app .

sudo docker run --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --user="$(id --user):$(id --group)" krypto_app
