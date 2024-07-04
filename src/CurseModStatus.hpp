
#ifndef CURSEMODSTATUS_HPP
#define CURSEMODSTATUS_HPP

namespace cf {

    enum class CurseModStatus {
        NEW = 1,
        CHANGES_REQUIRED = 2,
        UNDER_SOFT_REVIEW = 3,
        APPROVED = 4,
        REJECTED = 5,
        CHANGES_MADE = 6,
        INACTIVE = 7,
        ABANDONED = 8,
        DELETED = 9,
        UNDER_REVIEW = 10,
    };

}

#endif //CURSEMODSTATUS_HPP
