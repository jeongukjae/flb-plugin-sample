#ifndef __FLUENT_BIT_FLB_CONFIG_H__
#define __FLUENT_BIT_FLB_CONFIG_H__

// This header is simplified version of fluent bit configuration. The original
// is in
// https://github.com/fluent/fluent-bit/blob/master/include/fluent-bit/flb_config.h

#include <cstdlib>

typedef char *flb_sds_t;

// From monkey/mk_core/mk_list.h
struct mk_list {
  struct mk_list *prev, *next;
};

/* Configuration types */
#define FLB_CONFIG_MAP_STR 0        /* string */
#define FLB_CONFIG_MAP_STR_PREFIX 1 /* string that starts with  */
#define FLB_CONFIG_MAP_INT 2        /* integer */
#define FLB_CONFIG_MAP_BOOL 3       /* boolean */
#define FLB_CONFIG_MAP_DOUBLE 4     /* double */
#define FLB_CONFIG_MAP_SIZE 5       /* string size to integer (e.g: 2M) */
#define FLB_CONFIG_MAP_TIME 6 /* string time to integer seconds (e.g: 2H) */
#define FLB_CONFIG_MAP_DEPRECATED 7 /* for deprecated parameter */

#define FLB_CONFIG_MAP_CLIST 30   /* comma separated list of strings */
#define FLB_CONFIG_MAP_CLIST_1 31 /* split up to 1 node  + remaining data */
#define FLB_CONFIG_MAP_CLIST_2 32 /* split up to 2 nodes + remaining data */
#define FLB_CONFIG_MAP_CLIST_3 33 /* split up to 3 nodes + remaining data */
#define FLB_CONFIG_MAP_CLIST_4 34 /* split up to 4 nodes + remaining data */

#define FLB_CONFIG_MAP_SLIST 40   /* empty space separated list of strings */
#define FLB_CONFIG_MAP_SLIST_1 41 /* split up to 1 node  + remaining data */
#define FLB_CONFIG_MAP_SLIST_2 42 /* split up to 2 nodes + remaining data */
#define FLB_CONFIG_MAP_SLIST_3 43 /* split up to 3 nodes + remaining data */
#define FLB_CONFIG_MAP_SLIST_4 44 /* split up to 4 nodes + remaining data */

#define FLB_CONFIG_MAP_MULT 1

struct flb_config_map_val {
  union {
    int i_num;            /* FLB_CONFIG_MAP_INT */
    char boolean;         /* FLB_CONFIG_MAP_BOOL */
    double d_num;         /* FLB_CONFIG_MAP_DOUBLE */
    size_t s_num;         /* FLB_CONFIG_MAP_SIZE */
    flb_sds_t str;        /* FLB_CONFIG_MAP_STR */
    struct mk_list *list; /* FLB_CONFIG_MAP_CLIST and FLB_CONFIG_MAP_SLIST */
  } val;
  struct mk_list *mult;
  struct mk_list _head; /* Link to list if this entry is a 'multiple' entry */
};

struct flb_config_map {
  /* Public fields used by plugins at registration */
  int type;            /* type */
  flb_sds_t name;      /* property name */
  flb_sds_t def_value; /* default value */
  int flags;           /* option flags (e.g: multiple entries allowed) */
  int set_property;    /* set context property ? (use offset ?) */
  uintptr_t offset;    /* member offset */
  flb_sds_t desc;      /* description */

  struct flb_config_map_val value; /* lookup value */
  struct mk_list _head;
};

#endif  // __FLUENT_BIT_FLB_CONFIG_H__
