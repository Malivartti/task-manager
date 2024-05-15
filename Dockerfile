FROM postgres:latest

RUN apt-get update && apt-get install -y build-essential
RUN apt-get update && apt-get install -y qt6-base-dev
RUN apt-get update && apt-get install -y cmake
RUN apt-get update && apt-get install -y libqt6sql6-psql

# Compile and copy TCP server application
COPY . /app

WORKDIR /app

RUN cmake -S . -B build
RUN cmake --build build --config Release

EXPOSE 23232
ENV QT_DEBUG_PLUGINS=1

# Запуск сервера
CMD ./build/Server

# # Expose TCP port
# EXPOSE 23232

# CMD ["./Test"]