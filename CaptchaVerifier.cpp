#ifndef CAPTCHA_VERIFIER_HPP
#define CAPTCHA_VERIFIER_HPP

#include <string>
#include <random>
#include <algorithm>

class CaptchaVerifier {
private:
    std::string currentCode;
    const std::string characterPool = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

public:
    CaptchaVerifier() {
        generateNewChallenge();
    }

    // Generates a new random 6-character CAPTCHA string
    void generateNewChallenge(size_t length = 6) {
        currentCode.clear();
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<> distribution(0, characterPool.length() - 1);

        for (size_t i = 0; i < length; ++i) {
            currentCode += characterPool[distribution(generator)];
        }
    }

    // Returns the current CAPTCHA string so the host application can display it
    std::string getChallengeCode() const {
        return currentCode;
    }

    // Verifies the user's input against the token (supports optional case-insensitivity)
    bool verify(const std::string& userInput, bool caseSensitive = true) const {
        if (caseSensitive) {
            return userInput == currentCode;
        }

        // Case-insensitive verification path
        std::string lowerUser = userInput;
        std::string lowerCode = currentCode;
        std::transform(lowerUser.begin(), lowerUser.end(), lowerUser.begin(), ::tolower);
        std::transform(lowerCode.begin(), lowerCode.end(), lowerCode.begin(), ::tolower);
        
        return lowerUser == lowerCode;
    }
};

#endif // CAPTCHA_VERIFIER_HPP
