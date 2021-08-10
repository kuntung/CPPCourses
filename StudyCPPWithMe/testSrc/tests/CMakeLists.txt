add_executable(testComplex testComplex.cpp)
target_link_libraries(testComplex StudyCPPWithMe)

add_executable(testVirtualInhe testVirtualInhe.cpp)
add_executable(testVirtualFunc testVirtualFunc.cpp)
add_executable(objectSlicingTest objectSlicing.cpp)
add_executable(dynConstructTest dyncConstruct.cpp)
target_link_libraries(dynConstructTest StudyCPPWithMe)
add_executable(testRTII testRTII.cpp)
add_executable(testMyException testMyException.cpp)
add_executable(testSmartPtrs testSmartPtrs.cc)

# 模板实现栈
add_executable(testStack testStack.cpp)
target_link_libraries(testStack StudyCPPWithMe)

# 单例模式实现
add_executable(testSingleton testSingleton.cpp)
target_link_libraries(testSingleton StudyCPPWithMe)
