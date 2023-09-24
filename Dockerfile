FROM python:3.8.10

WORKDIR /app

COPY app.py .

RUN apt-get update && apt-get install -y \
    libx11-6 libxext-dev libxrender-dev \
    libxinerama-dev libxi-dev libxrandr-dev \
    libxcursor-dev libxtst-dev tk-dev && \
    rm -rf /var/lib/apt/list/*

CMD [ "python3", "app.py" ]