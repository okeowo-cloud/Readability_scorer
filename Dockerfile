FROM ubuntu:23.04 as base

WORKDIR /app

COPY . .

RUN ./prereqs.sh

FROM base as app_build_project

RUN ./build.sh

FROM app_build_project as app_run_test

RUN ./test.sh

FROM app_run_test as app_run_project

COPY $PWD/run.sh /bin

RUN chmod a+x /bin/run.sh

ENTRYPOINT ["/bin/run.sh"]
