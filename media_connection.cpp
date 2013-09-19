#include "media_connection.h"

namespace avtalk {

media_connection::media_connection()
{
    RTMP_Init(&rtmp_);
}

media_connection::~media_connection()
{
    RTMP_Close(&rtmp_);
}

bool media_connection::connect(const std::string& url)
{
    if(RTMP_SetupURL(&rtmp_, (char*)url.data()) < 0)
    {
        return false;
    }
    if(RTMP_Connect(&rtmp_, NULL) < 0)
    {
        return false;
    }
    return true;
}

bool media_connection::publish()
{
    RTMP_EnableWrite(&rtmp_);
    return RTMP_ConnectStream(&rtmp_, 0) >= 0;
}

bool media_connection::push_audio(const std::string &data, int timestamp)
{
    RTMPPacket packet;
    std::fill_n((char*)&packet, sizeof(packet), 0);
    packet.m_nBodySize = data.size();
    packet.m_body = (char*)data.data();
    packet.m_packetType = RTMP_PACKET_TYPE_AUDIO;
    packet.m_nTimeStamp = timestamp;
    return RTMP_SendPacket(&rtmp_, &packet, 0) >= 0;
}

void media_connection::start(const std::string& url)
{
    if(!(connect(url) && publish()))
    {
        std::cerr << "cannot connect to server" << std::endl;
    }
}

}
