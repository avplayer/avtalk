#pragma once
#include "common.h"
#include <pulse/simple.h>

namespace avtalk {

class audio_capture
{
public:
    audio_capture();
    ~audio_capture();

    void start();
    void stop();

public: //signals
    boost::signals2::signal<void(const uint8_t* data, std::size_t size, int timestamp)> read_frame;
private:
    pa_simple *s;
    bool running_;
};
}
