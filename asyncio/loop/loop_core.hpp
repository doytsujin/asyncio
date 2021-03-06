#pragma once

#include <asyncio/common.hpp>
#include <cstddef>
#include <cstdint>

BEGIN_ASYNCIO_NAMESPACE;
class TimerHandle;
typedef void (*TimerCallback)(TimerHandle *);

class LoopCore {
public:
public:
  virtual ~LoopCore() {}
  virtual void runOneIteration() = 0;
  virtual void close() = 0;
  virtual size_t activeHandlesCount() = 0;
  virtual uint64_t time() = 0;
  virtual TimerHandle *callSoon(TimerCallback callback, void *data) = 0;
  virtual TimerHandle *callSoonThreadSafe(TimerCallback callback,
                                          void *data) = 0;
  virtual TimerHandle *callLater(uint64_t milliseconds, TimerCallback callback,
                                 void *data) = 0;
};

END_ASYNCIO_NAMESPACE;