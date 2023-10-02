FROM python:3.8.10

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y \
    libx11-6 libxext-dev libxrender-dev \
    libxinerama-dev libxi-dev libxrandr-dev \
    libxcursor-dev libxtst-dev tk-dev libjpeg-dev gcc nano && \
    rm -rf /var/lib/apt/lists/*

RUN pip install Pillow

RUN gcc -shared -o gerar_dois_primos.so -c lib/c_functions/gerar_dois_primos.c -lm
RUN gcc -shared -o gerar_chave.so -c lib/c_functions/gerar_chave.c -lm
RUN gcc -shared -o encriptar.so -c lib/c_functions/encriptar.c -lm
RUN gcc -shared -o desencriptar.so -c lib/c_functions/desencriptar.c -lm

RUN gcc -shared -o criptografia_rsa.so gerar_dois_primos.so gerar_chave.so encriptar.so desencriptar.so

CMD [ "python3", "app.py" ]