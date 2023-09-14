#ifndef __NexCore_Core_FrameListener_H__
#define __NexCore_Core_FrameListener_H__

namespace nex {
    class FrameListener {
    public:
        virtual void onFrameStarted() {}
        virtual void onFramePrepare() {}
        virtual void onFrameEnded() {}
    };
}

#endif // __NexCore_Core_FrameListener_H__