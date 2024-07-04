#include "CurseEngine.hpp"
#include "CurseErrors.hpp"

namespace cf {
    CurseForgeAPI::CurseForgeAPI(const string &api_key) {
        this->api_key = api_key;
    }

    json CurseForgeAPI::fetch(const string &path) {
        // If the path starts with a slash, remove it
        string path_ = path;
        if (path_.front() == '/') {
            path_ = path_.substr(1);
        }
        auto headers = Header{
                    {"Accept", "application/json"},
                    {"x-api-key", this->api_key},
                    {"Content-Type", "application/json"},
                    };
        const auto response = Get(Url{CURSEFORGE_API + path_}, headers);

        try {
            return json::parse(response.text);
        } catch (const std::exception &e) {
            throw CurseAPIError(e.what());
        }

    }

    CurseForgeAPI::~CurseForgeAPI() = default;
}