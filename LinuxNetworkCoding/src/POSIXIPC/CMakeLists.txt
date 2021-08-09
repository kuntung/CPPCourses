add_executable(posixMQ posixMQ.cpp)
target_link_libraries(posixMQ rt) # 需要连接rt库

add_executable(unlinkPMQ unlinkPMQ.cpp)
target_link_libraries(unlinkPMQ rt)

add_executable(getaddrPMQ getaddrPMQ.cpp)
target_link_libraries(getaddrPMQ rt)

# setattr
add_executable(setattrPMQ setaddrPMQ.cpp)
target_link_libraries(setattrPMQ rt)

# send msg
add_executable(sendMSG2PMQ sendMSG2PMQ.cpp)
target_link_libraries(sendMSG2PMQ rt)


add_executable(recvMSGPMQ recvMSG.cpp)
target_link_libraries(recvMSGPMQ rt)

# 消息队列非空通知
add_executable(notifyPMQ notifyPMQ.cpp)
target_link_libraries(notifyPMQ rt)

## 共享内存
# 创建
add_executable(createPSHM createPSHM.cpp)
target_link_libraries(createPSHM rt)
# 修改大小
add_executable(resizePSHM resizePSHM.cpp)
target_link_libraries(resizePSHM rt)
# 获取属性
add_executable(statPSHM statPSHM.cpp)
target_link_libraries(statPSHM rt)
# 删除共享内存对象
add_executable(unlinkPSHM unlinkPSHM.cpp)
target_link_libraries(unlinkPSHM rt)

# mmap映射共享内存，并且写入数据
add_executable(writePSHM writePSHM.cpp)
target_link_libraries(writePSHM rt)
# mmap映射共享内存，并读出数据
add_executable(readPSHM readPSHM.cpp)
target_link_libraries(readPSHM rt)
