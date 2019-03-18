#ifndef FILEOPT_HHH
#define FILEOPT_HHH

#include <string>
#include <cassert>
#include <experimental/filesystem>
#include <vector>
#include <algorithm>
#include <memory>

namespace fs = std::experimental::filesystem;

class FileOpt {
public:
    static auto subFiles(const fs::path& father = "") {
        assert(CheckValidDir(father));
        
        std::vector<fs::path> subfiles;
        for(const auto& son : fs::directory_iterator(father)) 
            subfiles.emplace_back(son);
        std::sort(subfiles.begin(), subfiles.end());
        return subfiles;
    }

    static auto isValidDir(const fs::path& p) {
        return fs::is_directory(p);
    }

    static auto isValidFile(const fs::path& p) {
        return fs::is_regular_file(p);
    }
};

#endif //FILEOPT_HHH
