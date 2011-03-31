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
SET (realmserver_SRCS
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

SET(realmserver_LINK_FLAGS "")

add_executable(realmserver ${realmserver_SRCS})
add_definitions(
-D_LOGON_CONFIG_FILE='"${CONF_DIR}/RealmServer.conf"'
)
IF (DO_MYSQL)
   SET(realmserver_LINK_FLAGS "-pthread ${realmserver_LINK_FLAGS}")
ENDIF(DO_MYSQL)
IF (DO_POSTGRESQL)
   SET(realmserver_LINK_FLAGS "-pthread ${realmserver_LINK_FLAGS}")
ENDIF(DO_POSTGRESQL)

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   SET(realmserver_LINK_FLAGS "-framework Carbon ${realmserver_LINK_FLAGS}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(realmserver PROPERTIES LINK_FLAGS "${realmserver_LINK_FLAGS}")

target_link_libraries(
realmserver
shared
${SSLLIB}
${MYSQL_LIBRARIES}
${POSTGRESQL_LIBRARIES}
${OSX_LIBS}
${ACE_LIBRARY}
)

install(TARGETS realmserver DESTINATION bin)
