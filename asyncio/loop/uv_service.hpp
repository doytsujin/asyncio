#pragma once

#include <mutex>
#include <uv.h>

#include <asyncio/common.hpp>

#include "uv_timer_handle.hpp"

BEGIN_ASYNCIO_NAMESPACE;
class UVService {
public:
  UVService(uv_loop_t *uvLoop);
  virtual ~UVService() {}

  virtual void addHandle();
  virtual void subHandle();
  size_t activeHandlesCount() { return _activeHandles; }

  void startTimer(UVTimerHandleImp *);
  void stopTimer(UVTimerHandleImp *);

  virtual void doStartTimer(UVTimerHandleImp *) {}
  virtual void doStopTimer(UVTimerHandleImp *) {}

  uv_loop_t *getUVLoop() { return _uvLoop; }
  virtual void close();

protected:
  uv_loop_t *_uvLoop;
  size_t _activeHandles;
};

END_ASYNCIO_NAMESPACE;