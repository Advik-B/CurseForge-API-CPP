#include "CurseForgeAPI.hpp"
#include "CurseErrors.hpp"

namespace cf {
    CurseForgeAPI::CurseForgeAPI(const string &api_key) {
        this->api_key = api_key;
    }

    json CurseForgeAPI::fetch(const string &path, const Body &body) {
        // If the path starts with a slash, remove it
        string path_ = path;
        if (path_.front() == '/') {
            path_ = path_.substr(1);
        }
        auto headers = Header{
                        {"Accept", "application/json"},
                        {"x-api-key", this->api_key},
                        // {"Content-Type", "application/json"},
                        };
        if (body.c_str() != nullptr or body.c_str() != "") {
            headers["Content-Type"] = "application/json";
        }

        auto response = Get(Url{CURSEFORGE_API + path_}, body, headers);

        if (response.status_code != 200) {
            switch (response.status_code) {
                case 404:
                    throw errors::NotFoundError(CURSEFORGE_API+path_);
                default:
                    throw errors::CurseAPIError("CurseForge API returned status code " + std::to_string(response.status_code));
            }
        }

        try {
            return json::parse(response.text);
        } catch (std::exception &e) {
            throw errors::CurseAPIError(e);
        }
    }
}