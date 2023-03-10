#ifndef __FLUENT_BIT_FLB_TIME_H__
#define __FLUENT_BIT_FLB_TIME_H__

#include <cinttypes>
#include <cstring>
#include <ctime>

#include "msgpack.hpp"
#include "spdlog/spdlog.h"

#define ONESEC_IN_NSEC 1000000000

struct flb_time {
  struct timespec tm;
};

inline bool is_eventtime(const msgpack::object &obj) {
  if (obj.via.ext.type() != 0 || obj.via.ext.size != 8) {
    return false;
  }
  return true;
}

int flb_time_msgpack_to_time(struct flb_time &time,
                             const msgpack::object &obj) {
  uint32_t tmp;

  switch (obj.type) {
    case msgpack::type::POSITIVE_INTEGER:
      time.tm.tv_sec = obj.via.u64;
      time.tm.tv_nsec = 0;
      break;
    case msgpack::type::FLOAT:
      time.tm.tv_sec = obj.via.f64;
      time.tm.tv_nsec = ((obj.via.f64 - time.tm.tv_sec) * ONESEC_IN_NSEC);
      break;
    case msgpack::type::EXT:
      if (!is_eventtime(obj)) {
        spdlog::warn("[time] unknown ext type. type={} size={}",
                     obj.via.ext.type(), obj.via.ext.size);
        return -1;
      }
      memcpy(&tmp, obj.via.ext.data(), 4);
      time.tm.tv_sec = (uint32_t)ntohl(tmp);
      memcpy(&tmp, obj.via.ext.data() + 4, 4);
      time.tm.tv_nsec = (uint32_t)ntohl(tmp);
      break;
    default:
      spdlog::warn("[time] unknown time format {}", obj.type);
      return -1;
  }

  return 0;
}

#endif /* __FLUENT_BIT_FLB_TIME_H__ */
