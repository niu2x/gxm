#include <iostream>

#include <gxm/gxm.h>

int main() {
    // std::cout << "GXM Version: " << gxm::version::c_str()
    //           << std::endl;
    // std::cout << "GXM Version: " << gxm::version::major()
    //           << std::endl;
    GXM_LOG_D(gxm::version::c_str());
    return 0;
}