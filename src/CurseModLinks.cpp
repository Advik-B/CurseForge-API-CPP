
#include "CurseModLinks.hpp"
#include <iostream>
namespace cf {
    CurseModLinks CurseModLinks::from_json(const json &data) {
        // std::cout << data.dump(4) << std::endl;
        CurseModLinks links;
        if (data.contains("websiteUrl")) {
            links.websiteUrl = data["websiteUrl"];
        }
        if (data.contains("wikiUrl")) {
            links.wikiUrl = data["wikiUrl"];
        }
        if (data.contains("issuesUrl")) {
            links.issuesUrl = data["issuesUrl"];
        }
        if (data.contains("sourceUrl")) {
            links.sourceUrl = data["sourceUrl"];
        }
        return links;
    }
} // cf