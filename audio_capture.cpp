#include "audio_capture.h"
#include <boost/date_time.hpp>

namespace avtalk {
audio_capture::audio_capture()
	: running_(true)
	, formatCtx_(NULL)
{
    avdevice_register_all();
    AVInputFormat* inputFmt = av_find_input_format("pulse");
    AVDictionary* options = NULL;
    av_dict_set(&options, "sample_rate", "16000", 0);
    av_dict_set(&options, "channels", "1", 0);
    avformat_open_input(&formatCtx_, "default", inputFmt, &options);
    av_dict_free(&options);
}

audio_capture::~audio_capture()
{
    avformat_close_input(&formatCtx_);
}

void audio_capture::exec()
{
    using namespace boost::posix_time;
    char data[320];
    int error;
    running_ = true;
    ptime t0 = microsec_clock::local_time();
    while(running_)
    {
    	AVPacket pkt;
    	av_init_packet(&pkt);
    	av_read_frame(formatCtx_, &pkt);
    	std::cout << pkt.size << std::endl;
        time_duration d = microsec_clock::local_time() - t0;
        read_frame((uint8_t*)data, sizeof(data), d.total_milliseconds());
    	av_free_packet(&pkt);
    }
}

void audio_capture::stop()
{
    running_ = false;
}
}
