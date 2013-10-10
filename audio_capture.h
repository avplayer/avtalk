#pragma once
#include "common.h"
extern "C" {
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
}
namespace avtalk {

class audio_capture
{
public:
    audio_capture();
    ~audio_capture();

    void exec();
    void stop();

public: //signals
    boost::signals2::signal<void(const uint8_t* data, std::size_t size, int timestamp)> read_frame;
private:
    AVFormatContext *formatCtx_;
    bool running_;
};
}
