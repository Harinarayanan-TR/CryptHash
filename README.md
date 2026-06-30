# CryptHash
A simple hashing utility for terminal. Built in C++ in 5 minuites. 

On Debian/Ubuntu systems:
Bash

sudo apt-get update
sudo apt-get install build-essential libssl-dev

2. Compile the Source

Navigate to the directory containing your main.cpp file and compile using the -lcrypto linkage flag:
Bash

g++ -std=c++17 main.cpp -o crypthash -lcrypto

3. Make the Command Universal (System-Wide)

To run crypthash natively from any directory within your shell, move the generated binary to your local system executable path:
Bash

sudo mv crypthash /usr/local/bin/

macOS
1. Install Prerequisites

macOS requires the Xcode Command Line Tools and a package manager such as Homebrew to retrieve the OpenSSL development headers.
Bash

xcode-select --install
brew install openssl@3

2. Compile the Source

Homebrew installs OpenSSL to an independent directory structure. You must explicitly tell the compiler where to look for the includes and library flags:
Bash

g++ -std=c++17 main.cpp -o crypthash \\
    -I$(brew --prefix openssl@3)/include \\
    -L$(brew --prefix openssl@3)/lib \\
    -lcrypto

3. Make the Command Universal (System-Wide)

Move the compiled binary to your local system path folder:
Bash

sudo mv crypthash /usr/local/bin/

Windows
1. Install Prerequisites

    Install Microsoft Visual Studio (with the "Desktop development with C++" workload activated) or MinGW-w64.

    Download pre-compiled OpenSSL binaries for Windows (such as those from Win32/Win64 OpenSSL) or install it via the vcpkg dependency manager:
    DOS

    vcpkg install openssl:x64-windows

2. Compile the Source

If compiling via MinGW on a system where OpenSSL paths are registered:
DOS

g++ -std=c++17 main.cpp -o crypthash.exe -lcrypto

If using MSVC (Developer Command Prompt):
DOS

cl /EHsc /std:c++17 main.cpp /I"C:\\Path\\To\\OpenSSL\\include" /link /LIBPATH:"C:\\Path\\To\\OpenSSL\\lib" libcrypto.lib /out:crypthash.exe

3. Make the Command Universal (System-Wide)

    Move crypthash.exe to a permanent location (e.g., C:\\Program Files\\crypthash\\).

    Press Win + S, search for Edit the system environment variables, and open it.

    Click on the Environment Variables... button.

    Under System Variables, select the Path variable and click Edit.

    Click New and paste the path to the directory containing your executable (e.g., C:\\Program Files\\crypthash\\).

    Click OK on all windows to apply changes. Restart your command prompt or PowerShell instance.

Usage Guide

To launch the utility, simply invoke the command name across any active terminal application:
Plaintext

$ crypthash
crypthash engine activated. Type 'exit' to quit.
crypthash> hello
SHA-256: 2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824

crypthash> secure_password_123
SHA-256: 41b1a0641de0311ef3b429074d2b30ff52840c8fa21e258673f8e5e7869680ee

crypthash> exit
$

Memory Safety & Resource Management

The utility adheres strictly to standard memory containment practices:

    All allocations made via the OpenSSL C-API layout (EVP_MD_CTX_new) are explicitly paired with corresponding structural destructor sequences (EVP_MD_CTX_free) along every execution matrix path.

    This defensive coding design ensures that memory leaks are impossible, even if the user runs millions of hashes consecutively inside a single execution instance.
    """
TESTED ON FEDORA WORKSTATION 44. CONTACT ME IF IT BREAKS ON OTHER SYSTEMS
error40404.github@gmail.com
