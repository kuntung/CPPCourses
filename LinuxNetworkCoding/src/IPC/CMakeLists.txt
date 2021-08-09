add_executable(msgGet msgGet.cpp)
add_executable(msgRmv msgRmv.cpp)
add_executable(msgStat msgStat.cpp)
add_executable(msgChange msgChange.cpp)
add_executable(msgSend msgSend.cpp)
add_executable(msgRecv msgRecv.cpp)
add_executable(echoServIPC echoServ.cpp)
add_executable(echoCliIPC echoCli.cpp)
add_executable(mmapTest mmapTest.cpp)
add_executable(mmapRead mmapRead.cpp)
add_executable(shmwrite shmwrite.cpp)
add_executable(shmRead shmRead.cpp)
add_executable(shmRemove shmRemove.cpp)
add_executable(shmStat shmStat.cpp)

# 信号量
add_executable(semWrite semWrite.cpp)
add_executable(semCtl semCtl.cpp)
add_executable(semOpt semOpt.cpp)
add_executable(semTool semTool.cpp)
add_executable(semPrint semPrint.cpp)

# 哲学家就餐问题
add_executable(dining dining.cpp)
add_executable(diningDeadLock diningDeadLock.cpp)

