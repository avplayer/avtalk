#pragma once
#include "common.h"
#include <librtmp/rtmp.h>

namespace avtalk {

class media_connection
    : boost::noncopyable
{
public:
    media_connection();
    ~media_connection();

    bool connect(const std::string& url);

    bool publish();

    bool push_audio(const std::string& data, int timestamp);
    bool push_video();

    void start(const std::string& url);

private:
    RTMP rtmp_;
};
}
