/*
    ------------------------------------------------------------------------------------
    LICENSE:
    ------------------------------------------------------------------------------------
    This file is part of EVEmu: EVE Online Server Emulator
    Copyright 2006 - 2021 The EVEmu Team
    For the latest information visit https://evemu.dev
    ------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any later
    version.
    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
    You should have received a copy of the GNU Lesser General Public License along with
    this program; if not, write to the Free Software Foundation, Inc., 59 Temple
    Place - Suite 330, Boston, MA 02111-1307, USA, or go to
    http://www.gnu.org/copyleft/lesser.txt.
    ------------------------------------------------------------------------------------
    Author: Zhur
*/

#include "eve-server.h"

#include "crimewatch/CrimewatchService.h"

CrimewatchService::CrimewatchService(EVEServiceManager& mgr) :
    BindableService("crimewatch", mgr)
{
}

CrimewatchBound::CrimewatchBound(EVEServiceManager& mgr, CrimewatchService& parent, uint32 locationID, uint32 groupID) :
    EVEBoundObject(mgr, parent),
    m_locationID(locationID),
    m_groupID(groupID)
{
    this->Add("GetClientStates", &CrimewatchBound::GetClientStates);
    this->Add("SetSafetyLevel", &CrimewatchBound::SetSafetyLevel);
    this->Add("GetMySecurityStatus", &CrimewatchBound::GetMySecurityStatus);
    this->Add("GetCharacterSecurityStatus", &CrimewatchBound::GetCharacterSecurityStatus);
    this->Add("StartDuelChallenge", &CrimewatchBound::StartDuelChallenge);
    this->Add("RespondToDuelChallenge", &CrimewatchBound::RespondToDuelChallenge);
    this->Add("GetMyEngagements", &CrimewatchBound::GetMyEngagements);
}

BoundDispatcher* CrimewatchService::BindObject(Client* client, PyRep* bindParameters)
{
    Crimewatch_BindArgs args;
    PyRep* tmp(bindParameters->Clone());
    if (!args.Decode(&tmp)) {
        codelog(SERVICE__ERROR, "%s: Failed to decode bind args.", this->GetName().c_str());
        return nullptr;
    }

    return new CrimewatchBound(this->GetServiceManager(), *this, args.locationID, args.groupID);
}

void CrimewatchService::BoundReleased(CrimewatchBound* bound)
{
}

PyResult CrimewatchBound::GetClientStates(PyCallArgs& call)
{
    PyDict* result = new PyDict();
    
    PyDict* combatTimers = new PyDict();
    combatTimers->SetItemString("combatTimers", new PyList());
    combatTimers->SetItemString("duelTimers", new PyList());
    combatTimers->SetItemString("weaponTimers", new PyList());
    combatTimers->SetItemString("otherTimers", new PyList());
    result->SetItemString("combatTimers", combatTimers);
    
    PyDict* engagementsDict = new PyDict();
    result->SetItemString("engagements", engagementsDict);
    
    PyDict* flaggedChars = new PyDict();
    flaggedChars->SetItemString("chars", new PyList());
    flaggedChars->SetItemString("ships", new PyList());
    result->SetItemString("flaggedCharacters", flaggedChars);
    
    result->SetItemString("safetyLevel", new PyInt(3));
    
    return result;
}

PyResult CrimewatchBound::SetSafetyLevel(PyCallArgs& call, PyInt* safetyLevel)
{
    return PyStatic.NewTrue();
}

PyResult CrimewatchBound::GetMySecurityStatus(PyCallArgs& call)
{
    return new PyFloat(0.0f);
}

PyResult CrimewatchBound::GetCharacterSecurityStatus(PyCallArgs& call, PyInt* charID)
{
    return new PyFloat(0.0f);
}

PyResult CrimewatchBound::StartDuelChallenge(PyCallArgs& call, PyInt* charID)
{
    return PyStatic.NewTrue();
}

PyResult CrimewatchBound::RespondToDuelChallenge(PyCallArgs& call, PyInt* fromCharID, PyInt* expiryTime, PyBool* accept)
{
    return PyStatic.NewTrue();
}

PyResult CrimewatchBound::GetMyEngagements(PyCallArgs& call)
{
    PyDict* engagements = new PyDict();
    
    PyDict* engagement = new PyDict();
    engagement->SetItemString("engagementID", new PyInt(1));
    engagement->SetItemString("issuerID", new PyInt(1));
    engagement->SetItemString("charID", new PyInt(90000006));
    engagement->SetItemString("duration", new PyInt(300));
    engagement->SetItemString("expiredTime", new PyInt(0));
    engagement->SetItemString("status", new PyInt(1));
    engagement->SetItemString("typeID", new PyInt(1));
    engagement->SetItemString("level", new PyInt(1));
    engagement->SetItemString("factionID", new PyInt(0));
    engagement->SetItemString("weaponModifier", new PyInt(0));
    engagement->SetItemString("shieldModifier", new PyInt(0));
    engagement->SetItemString("armorModifier", new PyInt(0));
    engagement->SetItemString("hpModifier", new PyInt(0));
    
    engagements->SetItemString("1", engagement);
    
    return engagements;
}
