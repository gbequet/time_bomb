QT += widgets multimedia multimediawidgets

SOURCES += \
    creationsalon.cpp \
    fenetreprincipale.cpp \
    game_controller.cpp \
    home.cpp \
    jeuenligne.cpp \
    jeulocal.cpp \
    main.cpp \
    regles.cpp \
    reveal.cpp \
    salononline.cpp \
    game.cpp \
    cardjeu.cpp \
    player.cpp \
    card_controller.cpp \
    player_controller.cpp \
    plateau.cpp

HEADERS += \
    creationsalon.h \
    fenetreprincipale.h \
    game_controller.h \
    home.h \
    jeuenligne.h \
    jeulocal.h \
    regles.h \
    reveal.h \
    salononline.h \
    game.h \
    cardjeu.h \
    player.h \
    card_controller.h \
    player_controller.h \
    plateau.h

FORMS += \
    creationsalon.ui \
    home.ui \
    jeuenligne.ui \
    jeulocal.ui \
    regles.ui \
    reveal.ui \
    salononline.ui \
    plateau.ui

RESOURCES += \
    resources.qrc

CONFIG += resources_big
