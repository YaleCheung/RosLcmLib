#ifndef FILEPATH_HHH
#define FILEPATH_HHH

class FilePath {
public:
    template<int N>
    FilePath(const char(&name)[N]):
        _path(path),
        _size(N-1) {
        const char* has = _char_index(_path, '/'); // unix-like platform assumption;
        if(has) {
            _name = has + 1;
            _size -= static_cast<int>(_name - _path);
        } else 
            _name = _path; // relative path;
    }

    explicit FilePath(const char* path) :
        _path(path),
        _size(strlen(path)) {
        const char* has = _char_index(_path, '/'); // unix-like platform assumption;
        if (has) {
            _name = has + 1;
            _size -= static_cast<int>(_name - _path);
        } else 
            _name = _path; // relative path;
    }

    const char* getExtension() {
        const char* has = _char_index(_name, '.');
        if (has && has != _name) 
            // hiding file, start with '.'; eg: '.file' 
               return has + 1;
        return nullptr;
    }


private:
    const char* _char_index(const char* path, const char separator) {
        const char* ret = strchr(_path, separator);
        return ret;
    }
    const char* _path;
    const char* _name;
    int _size;
};
#endif //FILEPATH_HHH
