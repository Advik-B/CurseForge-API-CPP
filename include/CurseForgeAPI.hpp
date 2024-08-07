
#ifndef CURSEFORGEENGINE_HPP
#define CURSEFORGEENGINE_HPP

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>

namespace cf {
    using json = nlohmann::json;
    namespace json_ns = nlohmann::detail;
    using namespace cpr;
    using std::string;
    using std::optional;
    using std::nullopt;

    class CurseForgeAPI {
    private:
        const string CURSEFORGE_API = "https://api.curseforge.com/";
        // bool use_cache = false; // TODO: Implement cache
        string api_key;

    public:
        CurseForgeAPI(const string &api_key);
        json fetch(const string &path, const Body & body = {});
    };
};

#endif //CURSEFORGEENGINE_HPP
