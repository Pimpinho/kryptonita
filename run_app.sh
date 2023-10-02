#!/bin/bash
sudo docker build -t krypto_app .

sudo docker run --rm --name krypto_app -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --user="0:0" krypto_app
