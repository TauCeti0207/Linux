# CMake generated Testfile for 
# Source directory: /home/yzq0207/Desktop/Linux/cmake-demo/Demo6
# Build directory: /home/yzq0207/Desktop/Linux/cmake-demo/Demo6/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_run "Demo" "5" "2")
set_tests_properties(test_run PROPERTIES  _BACKTRACE_TRIPLES "/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;46;add_test;/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;0;")
add_test(test_usage "Demo")
set_tests_properties(test_usage PROPERTIES  PASS_REGULAR_EXPRESSION "Usage: .* base exponent" _BACKTRACE_TRIPLES "/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;49;add_test;/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;0;")
add_test(test_5_2 "Demo" "5" "2")
set_tests_properties(test_5_2 PROPERTIES  PASS_REGULAR_EXPRESSION "is 25" _BACKTRACE_TRIPLES "/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;55;add_test;/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;61;do_test;/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;0;")
add_test(test_10_5 "Demo" "10" "5")
set_tests_properties(test_10_5 PROPERTIES  PASS_REGULAR_EXPRESSION "is 100000" _BACKTRACE_TRIPLES "/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;55;add_test;/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;62;do_test;/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;0;")
add_test(test_2_10 "Demo" "2" "10")
set_tests_properties(test_2_10 PROPERTIES  PASS_REGULAR_EXPRESSION "is 1024" _BACKTRACE_TRIPLES "/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;55;add_test;/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;63;do_test;/home/yzq0207/Desktop/Linux/cmake-demo/Demo6/CMakeLists.txt;0;")
subdirs("math")
