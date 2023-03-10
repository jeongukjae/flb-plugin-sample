FROM ubuntu:20.04 as base_build

RUN apt-get update && \
    apt-get install -y build-essential curl && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

ARG BAZELISK_VERSION=1.16.0
ARG BAZELISK_ARCH=amd64

RUN curl -LO https://github.com/bazelbuild/bazelisk/releases/download/v${BAZELISK_VERSION}/bazelisk-linux-${BAZELISK_ARCH} && \
    chmod +x bazelisk-linux-amd64 && \
    mv bazelisk-linux-amd64 /usr/local/bin/bazel

WORKDIR /app
COPY . .
RUN bazel build //plugins

FROM fluent/fluent-bit:2.0 as fluent_bit

# TODO - copy all plugin files rather than specifying each one.
COPY --from=base_build /app/bazel-bin/plugins/filter_hello_world/flb-filter_hello_world.so /fluent-bit/

ENTRYPOINT ["/fluent-bit/bin/fluent-bit", \
    "-e", "/fluent-bit/flb-filter_hello_world.so"]
