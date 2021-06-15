#include <gxm/log.h>

int main() {
    gxm::log my_log;
    my_log.t("hello world");
    my_log.d("hello world");
    my_log.w("hello world");
    my_log.e("hello world");
    my_log.f("hello world");
    return 0;
}