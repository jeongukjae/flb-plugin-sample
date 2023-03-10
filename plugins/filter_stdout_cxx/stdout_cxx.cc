#include <cstdio>
#include <iostream>

#include "fluentbit/flb_config.h"
#include "fluentbit/flb_filter.h"
#include "fluentbit/flb_time.h"
#include "msgpack.hpp"
#include "spdlog/spdlog.h"

static int cb_stdout_init(struct flb_filter_instance *f_ins,
                          struct flb_config *config, void *data) {
  spdlog::set_pattern("[%Y/%m/%d %H:%M:%S] [%5!l] [stdout_cxx] %v");
  spdlog::info("Initializing stdout_cxx filter plugin");

  return 0;
}

static int cb_stdout_filter(const void *data, size_t bytes, const char *tag,
                            int tag_len, void **out_buf, size_t *out_bytes,
                            struct flb_filter_instance *f_ins,
                            struct flb_input_instance *i_ins,
                            void *filter_context, struct flb_config *config) {
  size_t off = 0;
  size_t cnt = 0;

  std::string tag_string(tag, tag_len);

  while (off != bytes) {
    msgpack::object_handle result =
        msgpack::unpack(static_cast<const char *>(data), bytes, off);

    msgpack::object deserialized = result.get();
    if (deserialized.type != msgpack::type::ARRAY) {
      spdlog::error("Unexpected type: {}", deserialized.type);
      return FLB_FILTER_NOTOUCH;
    }
    msgpack::object timeobj = deserialized.via.array.ptr[0];
    msgpack::object record = deserialized.via.array.ptr[1];

    flb_time time;
    if (flb_time_msgpack_to_time(time, timeobj) != 0) {
      spdlog::error("Failed to parse time");
      return FLB_FILTER_NOTOUCH;
    }

    std::cout << "[" << cnt++ << "] " << tag_string << ": [" << time.tm.tv_sec
              << "." << time.tm.tv_nsec << ", " << record << "]" << std::endl;
  }

  return FLB_FILTER_NOTOUCH;
}

static struct flb_config_map config_map[] = {
    /* EOF */
    {0}};

struct flb_filter_plugin filter_stdout_cxx_plugin = {
    .flags = 0,
    .name = "stdout_cxx",
    .description = "Filter events to STDOUT",
    .config_map = config_map,
    .cb_init = cb_stdout_init,
    .cb_filter = cb_stdout_filter,
    .cb_exit = NULL};
