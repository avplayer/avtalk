#include "audio_capture.h"
#include <pulse/error.h>
#include <boost/date_time.hpp>

namespace avtalk {
audio_capture::audio_capture()
{
    pa_sample_spec ss;
    ss.channels = 1;
    ss.format = PA_SAMPLE_S16LE;
    ss.rate = 16000;
    s = pa_simple_new(NULL, "avtalk", PA_STREAM_RECORD, NULL, "capture", &ss, NULL, NULL, NULL);
    if(s == NULL)
    {
        throw "cannot init pulseaudio";
    }
}

audio_capture::~audio_capture()
{
    pa_simple_free(s);
}

void audio_capture::start()
{
    using namespace boost::posix_time;
    char data[320];
    int error;
    running_ = true;
    ptime t0 = microsec_clock::local_time();
    while(running_)
    {
        if(pa_simple_read(s, data, sizeof(data), &error) < 0)
        {
            std::cerr << "error code: " << pa_strerror(error) << std::endl;
            break;
        }
        time_duration d = microsec_clock::local_time() - t0;
        read_frame((uint8_t*)data, sizeof(data), d.total_milliseconds());
    }
}

void audio_capture::stop()
{
    running_ = false;
}
}
