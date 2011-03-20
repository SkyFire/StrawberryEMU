INCLUDE_DIRECTORIES(
../../shared
../../shared/Configuration
../../shared/Cryptography
../../shared/Cryptography/Authentication
../../shared/Database
../../shared/DataStores
../../shared/Dynamic
../../shared/Dynamic/LinkedReference
../../shared/Logging
../../shared/Packets
../../shared/Threading
../../shared/Utilities
../../src
../../main/Achievements
../../main/Battlegrounds/Zones
../../main/AI/SmartAI
../../main/AI/ScriptedAI
../../main/AI/EventAI
../../main/AI/CoreAI
../../main/World
../../main/Weather
../../main/Tools
../../main/Tickets
../../main/Texts
../../main/Spells
../../main/Skills
../../main/Server
../../main/Scripting
../../main/Reputation
../../main/Quests
../../main/Pools
../../main/PCH
../../main/OutdoorPvP
../../main/Movement
../../main/Miscellaneous
../../main/Maps
../../main/Mails
../../main/Loot
../../main/Instances
../../main/Guilds
../../main/Groups
../../main/Grids
../../main/Globals
../../main/Spells/Auras
../../main/Server/Protocol/Handlers
../../main/Server/Protocol
../../main/Movement/Waypoints
../../main/Movement/MovementGenerators
../../main/Grids/Notifiers
../../main/Grids/Cells
../../main/Entities/Object/Updates
../../main/Entities/Item/Container
../../main/Entities/Vehicle
../../main/Entities/Unit
../../main/Entities/Transport
../../main/Entities/Totem
../../main/Entities/Player
../../main/Entities/Pet
../../main/Entities/Object
../../main/Entities/Item
../../main/Entities/GameObject
../../main/Entities/DynamicObject
../../main/Entities/Creature
../../main/Entities/Corpse
../../main/Events
../../main/Entities
../../main/DungeonFinding
../../main/DataStores
../../main/Conditions
../../main/Combat
../../main/Chat/Commands
../../main/Chat/Channels
../../main/Chat
../../main/Calendar
../../main/Battlegrounds
../../main/AuctionHouse
../../main/AI
../../main/Addons
../../main/Accounts
CommandLine
RA
Soap
WorldThread
../../scripts
../../dep
../../../dep/gsoap
../../../dep/mysql
../../../dep/mysql/include
../../../dep/mysql/extra/yassl/include
../../../dep/sockets
../../../dep/sockets/include
)

SET (worldserver_SRCS
../../../dep/gsoap/soapC.cpp
../../../dep/gsoap/soapServer.cpp
../../../dep/gsoap/stdsoap2.cpp
CommandLine/CliRunnable.cpp
Main.cpp
Master.cpp
RA/RARunnable.cpp
RA/RASocket.cpp
Soap/Soap.cpp
WorldThread/WorldRunnable.cpp

#WORLDSERVER HEADER FILES
../../../dep/gsoap/soapH.h
../../../dep/gsoap/soapStub.h
../../../dep/gsoap/stdsoap2.h
CommandLine/CliRunnable.h
Master.h
RA/RARunnable.h
RA/RASocket.h
RA/SocketDefines.h
Soap/Soap.h
WorldThread/WorldRunnable.h
)

SET(worldserver_LINK_FLAGS "")

add_executable(worldserver ${worldserver_SRCS})
add_definitions(
-D_WORLD_CONFIG_FILE='"${CONF_DIR}/WorldServer.conf"'
)
IF (DO_MYSQL)
    SET(worldserver_LINK_FLAGS "-pthread ${worldserver_LINK_FLAGS}")
ENDIF(DO_MYSQL)
IF (DO_POSTGRESQL)
    SET(worldserver_LINK_FLAGS "-pthread ${worldserver_LINK_FLAGS}")
ENDIF(DO_POSTGRESQL)

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    SET(worldserver_LINK_FLAGS "-framework Carbon ${WorldServer_LINK_FLAGS}")
    SET(SCRIPT_LIB "")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(worldserver PROPERTIES LINK_FLAGS "${worldserver_LINK_FLAGS}")

target_link_libraries(
worldserver
main
shared
zlib
g3dlib
${READLINE_LIBRARY}
${TERMCAP_LIBRARY}
gomp
${MYSQL_LIBRARIES}
${POSTGRESQL_LIBRARIES}
${SSLLIB}
${ACE_LIBRARY}
${ZLIB}
${OSX_LIBS}
)

install(TARGETS worldserver DESTINATION bin)
install(FILES run-worldserver DESTINATION bin)

