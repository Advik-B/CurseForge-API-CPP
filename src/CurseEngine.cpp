#include "CurseEngine.hpp"

namespace cf {
    CurseForgeAPI::CurseForgeAPI(const string &api_key) {
        this->api_key = api_key;
    }

    json CurseForgeAPI::fetch(string &path) {
        // If the path starts with a slash, remove it
        if (url[0] == '/') {
            url = url.substr(1);
        }
        auto headers = Header{
                    {"Accept", "application/json"},
                    {"x-api-key", this->api_key},
                    {"Content-Type", "application/json"},
                    };
        const auto response = Get(Url{CURSEFORGE_API + path}, headers);
        return json::parse(response.text);
    }

    CurseForgeAPI::~CurseForgeAPI() = default;
}