#include <iostream>
#include <string>

// #include <boost/program_options/cmdline.hpp>
// #include <boost/program_options/config.hpp>
// #include <boost/program_options/environment_iterator.hpp>
// #include <boost/program_options/eof_iterator.hpp>
// #include <boost/program_options/errors.hpp>
// #include <boost/program_options/option.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/positional_options.hpp>
// #include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
// #include <boost/program_options/version.hpp>

#include <gxm/script/lua/engine.h>
#include <gxm/base/version.h>
#include <gxm/common.h>

namespace po = boost::program_options;

namespace {

auto parse_command_line(int argc, const char *const argv[]) {
    po::positional_options_description p;
    p.add("launcher", -1);

    po::options_description desc("Allowed options");
    // clang-format off
    desc.add_options()
        ("help", "produce help message")
        ("launcher", po::value<std::string>(), "set launcher script")
    ;

    auto parsed_result = po::command_line_parser(argc, argv)
                        .options(desc)
                        .positional(p)
                        .run();
    // clang-format on

    po::variables_map vm;
    po::store(parsed_result, vm);
    po::notify(vm);

    bool no_any_options = vm.size() <= 0;
    bool show_help      = no_any_options || vm.count("help");
    if (show_help) {
        std::cout << desc << "\n";
        exit(EXIT_FAILURE);
    }

    return vm;
}

void test() {
    // auto x = gxm::base::string_utils::concat_with("\t", "1", 2,
    // "3", '4', 1024, std::string("hello")); gxm::base::log::d(x);
}

int run(int argc, const char *const argv[]) {
    gxm::base::log::d(
        std::string("GXM Version: ") + gxm::base::version::c_str());

    test();

    auto vm = parse_command_line(argc, argv);

    if (!vm.count("launcher")) {
        gxm::base::log::e("no launcher-script");
        return EXIT_FAILURE;
    }

    auto launcher = vm["launcher"].as<std::string>();

    gxm::script::lua::engine my_engine;
    my_engine.execute_file(launcher.c_str());

    return EXIT_SUCCESS;
}

} // namespace

int main(int argc, char *argv[]) {
    return run(argc, argv);
}