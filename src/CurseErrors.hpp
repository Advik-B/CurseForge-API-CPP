
#ifndef CURSEERRORS_HPP
#define CURSEERRORS_HPP

#include <exception>
#include <utility>

namespace cf {
    class CurseAPIError final : public std::exception {
    public:
        explicit CurseAPIError(std::string  message) : message(std::move(message)) {}
        [[nodiscard]] const char* what() const noexcept override {
            return message.c_str();
        }

        explicit CurseAPIError(const std::exception &e) : message(e.what()) {}
    private:
        std::string message;
    };
}

#endif //CURSEERRORS_HPP
