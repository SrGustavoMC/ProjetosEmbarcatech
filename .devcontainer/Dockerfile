FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04

# Instala as dependências do compilador ARM e o CMake conforme o pdf Unidade 3 - Capitulo 4
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    cmake \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    build-essential \
    python3 \
    git

# Esse codigo aqui tem o trabalho de clonar o SDK do Raspberry Pi Pico e atualizar os submódulos
ENV PICO_SDK_PATH=/opt/pico-sdk
RUN git clone --depth 1 --branch master https://github.com/raspberrypi/pico-sdk.git $PICO_SDK_PATH \
    && cd $PICO_SDK_PATH \
    && git submodule update --init