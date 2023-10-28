FROM ubuntu:23.04 as base

RUN apt update
RUN apt install vim build-essential cmake clang gcc ninja-build cmake-curses-gui -y
RUN apt install gcc python3 python3-cffi python3-pycparser python3-unittest2 python3.11-distutils python3.11-dev -y

WORKDIR /app

COPY . .

FROM base as app_build

RUN cmake . -B Build

FROM app_build as app_build_project

WORKDIR /app/Build

RUN make

FROM app_build_project as app_run_test

WORKDIR /app

RUN make all

FROM app_run_test as app_run_project

COPY $PWD/run.sh /bin

RUN chmod a+x /bin/run.sh

ENTRYPOINT ["/bin/run.sh"]
