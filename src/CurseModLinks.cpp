
#include "CurseModLinks.hpp"
#include <iostream>
namespace cf {
    CurseModLinks CurseModLinks::from_json(const json &data) {
        // std::cout << data.dump(4) << std::endl;
        CurseModLinks links;
        if (data.contains("websiteUrl") && !data["websiteUrl"].empty()) {
            links.websiteUrl = data["websiteUrl"];
        }
        if (data.contains("wikiUrl") && !data["wikiUrl"].empty()){
            links.wikiUrl = data["wikiUrl"];
        }
        if (data.contains("issuesUrl") && !data["issuesUrl"].empty()) {
            links.issuesUrl = data["issuesUrl"];
        }
        if (data.contains("sourceUrl") && !data["sourceUrl"].empty()) {
            links.sourceUrl = data["sourceUrl"];
        }
        return links;
    }
} // cf