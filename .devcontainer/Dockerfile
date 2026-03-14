FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04

# Instala as dependências do compilador ARM (C e C++) e o CMake
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    cmake \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib \
    build-essential \
    python3 \
    git

# Clona o SDK do Raspberry Pi Pico e atualiza os submódulos
ENV PICO_SDK_PATH=/opt/pico-sdk
RUN git clone --depth 1 --branch master https://github.com/raspberrypi/pico-sdk.git $PICO_SDK_PATH \
    && cd $PICO_SDK_PATH \
    && git submodule update --init