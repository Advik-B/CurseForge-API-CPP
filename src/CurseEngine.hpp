
#ifndef CURSEFORGEENGINE_HPP
#define CURSEFORGEENGINE_HPP

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>

namespace cf {
    using json = nlohmann::json;
    using namespace cpr;
    using std::string;

    class CurseForgeAPI {
    private:
        const string CURSEFORGE_API = "https://api.curseforge.com/";
        bool use_cache = false;
        string api_key;

    public:
        CurseForgeAPI(const string &api_key, bool use_cache = false);
        CurseForgeAPI(const string &api_key);
        ~CurseForgeAPI();
        json fetch(const string &path);
    };
};

#endif //CURSEFORGEENGINE_HPP
