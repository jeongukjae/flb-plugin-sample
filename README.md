# flb-plugin-sample

Fluent Bit plugin sample written in C/C++.

## How to build and run

```sh
$ docker build -t flb-plugin-sample .
$ docker run --rm -it test -i cpu -F stdout_cxx -m '*'
Fluent Bit v2.0.9
* Copyright (C) 2015-2022 The Fluent Bit Authors
* Fluent Bit is a CNCF sub-project under the umbrella of Fluentd
* https://fluentbit.io

[2023/03/10 15:53:10] [ info] [fluent bit] version=2.0.9, commit=4c0ca4fc5f, pid=1
[2023/03/10 15:53:10] [ info] [storage] ver=1.4.0, type=memory, sync=normal, checksum=off, max_chunks_up=128
[2023/03/10 15:53:10] [ info] [cmetrics] version=0.5.8
[2023/03/10 15:53:10] [ info] [ctraces ] version=0.2.7
[2023/03/10 15:53:10] [ info] [input:cpu:cpu.0] initializing
[2023/03/10 15:53:10] [ info] [input:cpu:cpu.0] storage_strategy='memory' (memory only)
[2023/03/10 15:53:10] [ info] [stdout_cxx] Initializing stdout_cxx filter plugin
[2023/03/10 15:53:10] [ info] [sp] stream processor started
[0] cpu.0: [1678463590.275378839, {"cpu_p":0,"user_p":0,"system_p":0,"cpu0.p_cpu":0,"cpu0.p_user":0,"cpu0.p_system":0,"cpu1.p_cpu":0,"cpu1.p_user":0,"cpu1.p_system":0,"cpu2.p_cpu":0,"cpu2.p_user":0,"cpu2.p_system":0,"cpu3.p_cpu":0,"cpu3.p_user":0,"cpu3.p_system":0,"cpu4.p_cpu":0,"cpu4.p_user":0,"cpu4.p_system":0,"cpu5.p_cpu":0,"cpu5.p_user":0,"cpu5.p_system":0,"cpu6.p_cpu":0,"cpu6.p_user":0,"cpu6.p_system":0,"cpu7.p_cpu":0,"cpu7.p_user":0,"cpu7.p_system":0}]
[0] cpu.0: [1678463591.276133756, {"cpu_p":0.125,"user_p":0,"system_p":0.125,"cpu0.p_cpu":0,"cpu0.p_user":0,"cpu0.p_system":0,"cpu1.p_cpu":0,"cpu1.p_user":0,"cpu1.p_system":0,"cpu2.p_cpu":0,"cpu2.p_user":0,"cpu2.p_system":0,"cpu3.p_cpu":0,"cpu3.p_user":0,"cpu3.p_system":0,"cpu4.p_cpu":1,"cpu4.p_user":1,"cpu4.p_system":0,"cpu5.p_cpu":0,"cpu5.p_user":0,"cpu5.p_system":0,"cpu6.p_cpu":0,"cpu6.p_user":0,"cpu6.p_system":0,"cpu7.p_cpu":0,"cpu7.p_user":0,"cpu7.p_system":0}]
[0] cpu.0: [1678463592.278890923, {"cpu_p":0.25,"user_p":0.125,"system_p":0.125,"cpu0.p_cpu":0,"cpu0.p_user":0,"cpu0.p_system":0,"cpu1.p_cpu":0,"cpu1.p_user":0,"cpu1.p_system":0,"cpu2.p_cpu":0,"cpu2.p_user":0,"cpu2.p_system":0,"cpu3.p_cpu":0,"cpu3.p_user":0,"cpu3.p_system":0,"cpu4.p_cpu":0,"cpu4.p_user":0,"cpu4.p_system":0,"cpu5.p_cpu":0,"cpu5.p_user":0,"cpu5.p_system":0,"cpu6.p_cpu":0,"cpu6.p_user":0,"cpu6.p_system":0,"cpu7.p_cpu":0,"cpu7.p_user":0,"cpu7.p_system":0}]
[0] cpu.0: [1678463593.280610299, {"cpu_p":0,"user_p":0,"system_p":0,"cpu0.p_cpu":0,"cpu0.p_user":0,"cpu0.p_system":0,"cpu1.p_cpu":0,"cpu1.p_user":0,"cpu1.p_system":0,"cpu2.p_cpu":0,"cpu2.p_user":0,"cpu2.p_system":0,"cpu3.p_cpu":0,"cpu3.p_user":0,"cpu3.p_system":0,"cpu4.p_cpu":0,"cpu4.p_user":0,"cpu4.p_system":0,"cpu5.p_cpu":1,"cpu5.p_user":0,"cpu5.p_system":1,"cpu6.p_cpu":0,"cpu6.p_user":0,"cpu6.p_system":0,"cpu7.p_cpu":0,"cpu7.p_user":0,"cpu7.p_system":0}]
...
^C[2023/03/10 15:53:29] [engine] caught signal (SIGINT)
[2023/03/10 15:53:29] [ warn] [engine] service will shutdown in max 5 seconds
[2023/03/10 15:53:29] [ info] [input] pausing cpu.0
[2023/03/10 15:53:30] [ info] [engine] service has stopped (0 pending tasks)
[2023/03/10 15:53:30] [ info] [input] pausing cpu.0
$ docker run --rm -it test -i cpu -F hello_world -m '*'
Fluent Bit v2.0.9
* Copyright (C) 2015-2022 The Fluent Bit Authors
* Fluent Bit is a CNCF sub-project under the umbrella of Fluentd
* https://fluentbit.io

[2023/03/10 15:54:36] [ info] [fluent bit] version=2.0.9, commit=4c0ca4fc5f, pid=1
[2023/03/10 15:54:36] [ info] [storage] ver=1.4.0, type=memory, sync=normal, checksum=off, max_chunks_up=128
[2023/03/10 15:54:36] [ info] [cmetrics] version=0.5.8
[2023/03/10 15:54:36] [ info] [ctraces ] version=0.2.7
[2023/03/10 15:54:36] [ info] [input:cpu:cpu.0] initializing
[2023/03/10 15:54:36] [ info] [input:cpu:cpu.0] storage_strategy='memory' (memory only)
[2023/03/10 15:54:36] [ info] [sp] stream processor started
Hello, World!
Hello, World!
Hello, World!
^C[2023/03/10 15:54:38] [engine] caught signal (SIGINT)
[2023/03/10 15:54:38] [ warn] [engine] service will shutdown in max 5 seconds
[2023/03/10 15:54:38] [ info] [input] pausing cpu.0
[2023/03/10 15:54:39] [ info] [engine] service has stopped (0 pending tasks)
[2023/03/10 15:54:39] [ info] [input] pausing cpu.0
```

## How to make the plugin loadable

Specific criteria need to be met to make the plugin loadable in Fluent Bit, [as the fluent bit's documentation says](https://docs.fluentbit.io/manual/development/developer-guide#plugin-api). The plugin must be a shared object file with a name in the format of `flb-{PLUGIN_NAME}.so`, and contain the `{PLUGIN_NAME}_plugin` symbol. This symbol should adhere to the interface of the respective plugin type.

In this repository, a filter plugin has been implemented, meaning that the plugin follows the filter plugin interface.
After building the plugin in the Docker container, it is passed as a parameter to the Fluent Bit container, allowing Fluent Bit to load the plugin.
