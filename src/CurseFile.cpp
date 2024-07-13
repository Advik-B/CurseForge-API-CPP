
#include "CurseFile.hpp"

namespace cf {
    CurseFile CurseFile::from_json(const json &data) {
        // std::cout << data.dump(4) << std::endl;
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
        if (data.contains("downloadUrl")) {
            file.downloadUrl = data["downloadUrl"];
        }
        for (const auto &version : data["gameVersions"]) {
            file.gameVersions.push_back(version);
        }
        for (const auto &version : data["sortableGameVersions"]) {
            file.sortableGameVersions.push_back(CurseSortableGameVersion::from_json(version));
        }
        for (const auto &dependency : data["dependencies"]) {
            file.dependencies.push_back(CurseFileDependency::from_json(dependency));
        }

        if (data.contains("exposeAsAlternative")) {
            file.exposeAsAlternative = data["exposeAsAlternative"];
        }
        if (data.contains("parentProjectFileId")) {
            file.parentProjectFileId = data["parentProjectFileId"];
        }
        if (data.contains("alternateFileId")) {
            file.alternateFileId = data["alternateFileId"];
        }
        if (data.contains("isServerPack")) {
            file.isServerPack = data["isServerPack"];
        }
        if (data.contains("serverPackFileId")) {
            file.serverPackFileId = data["serverPackFileId"];
        }
        if (data.contains("serverPackFileId")) {
            file.serverPackFileId = data["serverPackFileId"];
        }
        if (data.contains("isEarlyAccessContent")) {
            file.isEarlyAccessContent = data["isEarlyAccessContent"];
        }
        if (data.contains("earlyAccessEndDate")) {
            file.earlyAccessEndDate = data["earlyAccessEndDate"];
        }
        file.fileFingerprint = data["fileFingerprint"];

        for (const auto &module : data["modules"]) {
            file.modules.push_back(CurseFileModule::from_json(module));
        }

        return file;
    }
} // cf