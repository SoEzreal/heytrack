find_package(Qt4 REQUIRED)
find_package(Phonon REQUIRED)
find_package(QJSON REQUIRED)

include_directories(${QT_INCLUDE_DIR} ${QJSON_INCLUDE_DIRS} ${PHONON_INCLUDE_DIR})

set(HeyTrack_Core_SRCS
    AbstractServer.cpp
    AbRadioServer.cpp
    RockmaxServer.cpp
    SomaFmServer.cpp
    AbstractPlayer.cpp
    PhononPlayer.cpp
    StationModel.cpp
    FormatModel.cpp
    GenreModel.cpp
    Style.cpp
)

set(HeyTrack_Core_HDRS
    AbstractServer.h
    AbRadioServer.h
    RockmaxServer.h
    SomaFmServer.h
    AbstractPlayer.h
    StationModel.h
    FormatModel.h
    GenreModel.h
)

if(NOT WIN32)
    set(HeyTrack_Core_SRCS
        ${HeyTrack_Core_SRCS}
        VlcPlayer.cpp
        AmarokPlayer.cpp
    )

    set(HeyTrack_Core_HDRS
        ${HeyTrack_Core_HDRS}
        AmarokPlayer.h
    )
endif()

qt4_wrap_cpp(HeyTrack_Core_MOC ${HeyTrack_Core_HDRS})

qt4_add_resources(HeyTrack_Core_QRC
    graphics/graphics.qrc
)

add_library(HeyTrackCore SHARED ${HeyTrack_Core_SRCS} ${HeyTrack_Core_MOC} ${HeyTrack_Core_QRC})
target_link_libraries(HeyTrackCore
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY}
    ${QT_QTNETWORK_LIBRARY}
    ${QT_QTXMLPATTERNS_LIBRARY}
    ${QT_QTDBUS_LIBRARY}
    ${QJSON_LIBRARIES}
    ${QT_PHONON_LIBRARY}
)

install(TARGETS HeyTrackCore DESTINATION ${HEYTRACK_LIBRARY_DIR})
