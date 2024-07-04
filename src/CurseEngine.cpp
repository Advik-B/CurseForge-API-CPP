#include "CurseEngine.hpp"

namespace cf {
    CurseForgeAPI::CurseForgeAPI(const string &api_key) {
        this->api_key = api_key;
    }

    json CurseForgeAPI::fetch(const string &url) {
        auto headers = Header{
                    {"Accept", "application/json"},
                    {"x-api-key", this->api_key},
                    {"Content-Type", "application/json"},
                    };
        const auto response = Get(Url{CURSEFORGE_API + url}, headers);
        return json::parse(response.text);
    }

    CurseForgeAPI::~CurseForgeAPI() = default;
}