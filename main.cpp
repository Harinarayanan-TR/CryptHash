#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/evp.h> 

// Modern OpenSSL 3.0+ Hashing Function
std::string generateSHA256(const std::string& input) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if (context == nullptr) {
        return "";
    }

    if (EVP_DigestInit_ex(context, EVP_sha256(), nullptr) != 1) {
        EVP_MD_CTX_free(context);
        return "";
    }

    if (EVP_DigestUpdate(context, input.c_str(), input.length()) != 1) {
        EVP_MD_CTX_free(context);
        return "";
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int length = 0;

    if (EVP_DigestFinal_ex(context, hash, &length) != 1) {
        EVP_MD_CTX_free(context);
        return "";
    }

    EVP_MD_CTX_free(context);

    std::stringstream ss;
    for (unsigned int i = 0; i < length; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// The Extension Loop
int main() {
    std::string inputLine;
    std::cout << "crypthash engine activated. Type 'exit' to quit.\n";

    while (true) {
        std::cout << "crypthash> ";
        if (!std::getline(std::cin, inputLine)) break;

        if (inputLine.empty()) continue;

        if (inputLine == "exit") {
            break;
        }

        std::string hashedResult = generateSHA256(inputLine);
        std::cout << "SHA-256: " << hashedResult << "\n\n";
    }

    return 0;
}
