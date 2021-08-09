add_executable(createThread createThread.cpp)
target_link_libraries(createThread pthread)

# 用多线程改写回射服务器
add_executable(echoServThread echoServThread.cpp)
target_link_libraries(echoServThread pthread)
# 回射客户端
add_executable(echoCliThread echoCliThread.cpp)
target_link_libraries(echoCliThread pthread)

# 线程特定数据
add_executable(TSD TSD.cpp)
target_link_libraries(TSD pthread)

# 生产者消费者问题
add_executable(ProAndCustomer ProAndCustomer.cpp)
target_link_libraries(ProAndCustomer pthread rt)
# 条件变量实现
add_executable(PCWithCond PCWithCond.cpp)
target_link_libraries(PCWithCond pthread)
