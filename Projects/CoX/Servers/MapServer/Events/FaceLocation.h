/*
 * SEGS - Super Entity Game Server
 * http://www.segs.io/
 * Copyright (c) 2006 - 2018 SEGS Team (see AUTHORS.md)
 * This software is licensed under the terms of the 3-clause BSD License. See LICENSE.md for details.
 */

#pragma once

#include "GameCommandList.h"
#include "MapEvents.h"
#include "MapLink.h"

#include <QtCore/QString>

class FaceLocation : public GameCommand
{
public:
    FaceLocation(glm::vec3 loc) : GameCommand(MapEventTypes::evFaceLocation),
        m_loc(loc)
    {}

    // SerializableEvent interface
    void serializefrom(BitStream &src);
    void serializeto(BitStream &bs) const override {
        bs.StorePackedBits(1,type()-MapEventTypes::evFirstServerToClient);
        bs.StoreFloat(m_loc.x);
        bs.StoreFloat(m_loc.y);
        bs.StoreFloat(m_loc.z);
    }
    
protected:
    glm::vec3 m_loc;
};