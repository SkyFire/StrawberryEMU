INCLUDE_DIRECTORIES(
../../shared
../../shared/Cryptography
../../shared/Cryptography/Authentication
../../shared/Database
../../shared/Database/Implementation
../../shared/Logging
../../shared/Packets
../../shared/Threading
../../shared/Utilities
../../main/Entities/Object
../../../dep/mysql
../../../dep/mersennetwister
../../../dep/utf8cpp
../../../dep/mysql/extra/yassl/include
../../../dep/sockets/include
../../../dep/sockets
../../../dep
../../../dep/mysql/include
../../../dep/g3dlite/include
../../../dep/g3dlite
)
SET (logonserver_SRCS
Auth/AuthCodes.cpp
Auth/AuthCodes.h
Main.cpp
Realms/RealmList.cpp
Realms/RealmList.h
Server/AuthSocket.cpp
Server/AuthSocket.h
Server/RealmAcceptor.h
Server/RealmSocket.cpp
Server/RealmSocket.h
)

SET(logonserver_LINK_FLAGS "")

add_executable(logonserver ${logonserver_SRCS})
add_definitions(
-D_LOGON_CONFIG_FILE='"${CONF_DIR}/LogonServer.conf"'
)
IF (DO_MYSQL)
   SET(logonserver_LINK_FLAGS "-pthread ${logonserver_LINK_FLAGS}")
ENDIF(DO_MYSQL)
IF (DO_POSTGRESQL)
   SET(logonserver_LINK_FLAGS "-pthread ${logonserver_LINK_FLAGS}")
ENDIF(DO_POSTGRESQL)

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   SET(logonserver_LINK_FLAGS "-framework Carbon ${logonserver_LINK_FLAGS}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(logonserver PROPERTIES LINK_FLAGS "${logonserver_LINK_FLAGS}")

target_link_libraries(
logonserver
shared
${SSLLIB}
${MYSQL_LIBRARIES}
${POSTGRESQL_LIBRARIES}
${OSX_LIBS}
${ACE_LIBRARY}
)

install(TARGETS logonserver DESTINATION bin)
