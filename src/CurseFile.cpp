
#include "CurseFile.hpp"

namespace cf {
    CurseFile CurseFile::from_json(const json &data) {
        CurseFile file;
        file.id = data["id"];
        file.gameId = data["gameId"];
        file.modId = data["modId"];
        file.isAvailable = data["isAvailable"];
        file.displayName = data["displayName"];
        file.fileName = data["fileName"];
        file.releaseType = static_cast<CurseFileReleaseType>(data["releaseType"]);
        file.fileStatus = static_cast<CurseFileStatus>(data["fileStatus"]);
        for (const auto &hash : data["hashes"]) {
            file.hashes.push_back(CurseFileHash::from_json(hash));
        }
        file.fileDate = data["fileDate"];
        file.fileLength = data["fileLength"];
        file.downloadCount = data["downloadCount"];
        if (data.contains("fileSizeOnDisk")) {
            file.fileSizeOnDisk = data["fileSizeOnDisk"];
        }
        file.downloadUrl = data["downloadUrl"];
        for (const auto &version : data["gameVersions"]) {
            file.gameVersions.push_back(version);
        }
        for (const auto &version : data["sortableGameVersions"]) {
            file.sortableGameVersions.push_back(CurseSortableGameVersion::from_json(version));
        }
        for (const auto &dependency : data["dependencies"]) {
            file.dependencies.push_back(CurseFileDependency::from_json(dependency));
        }
    }
} // cf