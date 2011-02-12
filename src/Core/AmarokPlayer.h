#ifndef HeyTrack_Core_AmarokPlayer_h
#define HeyTrack_Core_AmarokPlayer_h
/*
    Copyright © 2009, 2010, 2011 Vladimír Vondruš <mosra@centrum.cz>
    Copyright © 2010 Jan Dupal <dupal.j@seznam.cz>

    This file is part of HeyTrack.

    HeyTrack is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    HeyTrack is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

/** @file
 * @brief Class HeyTrack::Core::AmarokPlayer
 */

#include "AbstractPlayer.h"

class QDBusInterface;
class QNetworkAccessManager;
class QNetworkReply;

namespace HeyTrack { namespace Core {

class AmarokPlayer: public AbstractPlayer {
    Q_OBJECT

    PLAYER_DEFINE(AmarokPlayer)

    protected:
        /** @brief Network access manager */
        QNetworkAccessManager* manager;

    public:
        AmarokPlayer(QObject* parent = 0);
        virtual bool isPlaying();
        virtual void play(const QString& url);
        virtual void stop();

    private slots:
        virtual void processPlaylist(QNetworkReply* reply);

    private:
        QDBusInterface *playerInterface,
            *tracklistInterface;
};

}}

#endif
