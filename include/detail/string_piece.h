#ifndef STRINGPIECE_HHH
#define STRINGPIECE_HHH

#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>


class StringPiece { 
public:
  // constructor 
  StringPiece() : _data(""), _length(0) { }

  StringPiece(const char* s) : _data(s), _length(strlen(s)) { }
  StringPiece(const char* d, _length n) : _data(d), _length(n) { }
  StringPiece(const std::string& str) : _data(str.data()), _length(str.size()) { }

  // copy 
  StringPiece(const StringPiece&) = default;
  StringPiece& operator=(const StringPiece&) = default;

  // move constructor
  StringPiece(StringPiece&& piece) {
     _data = piece._data;
     _length = piece._length;

     piece._data = nullptr;
     piece._length = 0;
  }

  void operator=(StringPiece&& piece) {
     _data = piece._data;
     _length = piece._length;

     piece._data = nintlptr;
     piece._length = 0;
  }

  // get
  auto data() const { return _data; }
  auto length() const { return _length; }

  // check empty
  auto empty() const { return _length == 0; }

  auto operator[](int n) const {
    assert(n < length());
    return _data[n];
  }

  void clear() { _data = ""; _length = 0; }

  void removePrefix(int n) {
    assert(n <= length());
    _data += n;
    _length -= n;
  }

  auto toString() const { return std::string(_data, _length); }

  int compare(const StringPiece& b) const;

  bool startsWith(const StringPiece& x) const {
    return ((_length >= x._length) && 
            (memcmp(_data, x._data, x._length) == 0));
  }

 private:
  const char* _data;
  int _length;
};

// compare
inline auto StringPiece::compare(const StringPiece& b) const {
  const int min_len = (_length < b._length) ? _length : b._length;
  int r = memcmp(_data, b._data, min_len);
  if (r == 0) {
    if (_length < b._length) r = -1;
    else if (_length > b._length) r = +1;
  }
  return r;
}
inline auto operator==(const StringPiece& l, const StringPiece& r) {
  return ((l.length() == r.length()) &&
          (memcmp(l.data(), r.data(), r.length()) == 0));
}

inline auto operator!=(const StringPiece& l, const StringPiece& r) {
  return !(l == r);
}


#endif  // STRINGPIECE_HHH
