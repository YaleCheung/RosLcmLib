#ifndef BUFFER_HHH
#define BUFFER_HHH

#include <cstring>
#
nclude <cstdint>

constexpr uint32_t DEFAULT = 4000; // 4k buffer

template<uint32_t BUFFERSIZE = DEFAULT> 
class Buffer {
public:
    Buffer() : 
        _cur_avail_pos(0), 
        _size(DEFAULT) { 
            //bzero is ignored for performance;
    }
    // append a piece of data
    void append(const char* data, uint32_t len) {
        if (len < reminder()) {
            memcpy(_buf + _cur_avail_pos, data, len);
            _cur_avail_pos += len;
        
    }
    //
    bool try_append(const char* data, uint32_t len) {
        if (len > reminder()) 
            return false;
        else {
            memcpy(_buf + _cur_avail_pos, data, len);
            _cur_avail_pos += len;
        }
        return true;
    }

    // if the buffer cannot load the whole data, then return the left bytes of data;
    uint32_t partial_append (const char* data, uint32_t len) {
        auto left = reminder();
        if (len > left) {
            memcpy(_buf + _cur_avail_pos, data, left);
            _cur_avail_pos = BUFFERSIZE - 1;
            return len - left;
        } else {
            memcpy(_buf + _cur_avail_pos, data, len);
            _cur_avail_pos += len;
            return 0;
        }
    }

    const char* data() const {
        return _buf; 
    }

    const char* current() const {
        return _buf + _cur_avail_pos;
    }

    uint32_t reminder() const {
        return _size - _cur_avail_pos;
    }

    uint32_t length() const {
        return _cur_avail_pos;
    }

    std::string toString() {
        return std::string(_buf, _cur_avail_pos);
    }

    StringPiece toStringPiece() {
        return StringPiece(_buf, _cur_avail_pos);
    }
    
    // flush
    void reset() {
        _cur_avail_pos = 0;
    }

    // warn: the op impacts performance, use _cur_avail_pos to represent the status of buf;
    void bZero() {
        memset(buf, '\0', _size);
    }
    
private:
    uint32_t _cur_avail_pos;
    char _buf[DEFAULT];
    constexpr uint32_t _size;
}
#endif
