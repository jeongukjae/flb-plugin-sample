#include <iostream>

#include "fluentbit/flb_config.h"
#include "fluentbit/flb_filter.h"

static int cb_hello_world_filter(const void *data, size_t bytes,
                                 const char *tag, int tag_len, void **out_buf,
                                 size_t *out_bytes,
                                 struct flb_filter_instance *f_ins,
                                 struct flb_input_instance *i_ins,
                                 void *filter_context,
                                 struct flb_config *config) {
  std::cout << "Hello, World!" << std::endl;
  return FLB_FILTER_NOTOUCH;
}

static struct flb_config_map config_map[] = {
    /* EOF */
    {0}};

struct flb_filter_plugin filter_hello_world_plugin = {
    .flags = 0,
    .name = "hello_world",
    .description = "Print 'Hello, World!' to stdout",
    .config_map = config_map,
    .cb_init = NULL,
    .cb_filter = cb_hello_world_filter,
    .cb_exit = NULL};
