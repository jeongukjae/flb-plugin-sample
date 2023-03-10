#ifndef __FLUENT_BIT_FLB_FILTER_H__
#define __FLUENT_BIT_FLB_FILTER_H__

// This is the simplified filter plugin interface. The original is in
// https://github.com/fluent/fluent-bit/blob/master/include/fluent-bit/flb_filter.h

#include <cstdlib>

#include "fluentbit/flb_config.h"

#define FLB_FILTER_MODIFIED 1
#define FLB_FILTER_NOTOUCH  2

struct flb_filter_plugin {
  int flags;         /* Flags (not available at the moment */
  char *name;        /* Filter short name            */
  char *description; /* Description                  */

  /* Config map */
  struct flb_config_map *config_map;

  /* Callbacks */
  int (*cb_init)(struct flb_filter_instance *, struct flb_config *, void *);
  int (*cb_filter)(const void *, size_t, const char *, int, void **, size_t *,
                   struct flb_filter_instance *, struct flb_input_instance *,
                   void *, struct flb_config *);
  int (*cb_exit)(void *, struct flb_config *);

  struct mk_list _head; /* Link to parent list (config->filters) */
};

#endif  // __FLUENT_BIT_FLB_FILTER_H__
