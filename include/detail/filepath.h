#ifndef FILEPATH_HHH
#define FILEPATH_HHH

class FilePath {
public:
    template<int N>
    FilePath(const char(&name)[N]):
        _path(path),
        _size(N-1) {
 		#ifdef _WIN32
        auto has = _char_index(_path, '\\');
        #else
        auto has = _char_index(_path, '/'); // unix-like platform assumption;
        #endif
        if(has) {
            _name = has + 1;
            _size -= static_cast<int>(_name - _path);
        } else ()
            _name = _path; // relative path;
    }

    explicit FilePath(const char* path) :
        _path(path),
        _size(strlen(path)) {
        auto has = _char_index(_path, '/'); // unix-like platform assumption;
        if (has) {
            _name = has + 1;
            _size -= static_cast<int>(_name - _path);
        } else 
            _name = _path; // relative path;
    }

    const char* getExtension() {
        // hiding file ignored, start with '.'; eg: '.file' 
        auto has = _char_index(_name, '.');
        if (has && has != _name) 
            has = has + 1;
        return has;
    }

private:
    const char* _char_index(const char* path, const char separator) {
        for(auto ptr = path; *ptr != '\0'; ++ ptr) {
            if (separator == *ptr) {
                ptr = ptr + 1;
                return ptr;
        }
        return nullptr;
    }
    const char* _path;
    const char* _name;
    int _size;
};
#endif //FILEPATH_HHH
