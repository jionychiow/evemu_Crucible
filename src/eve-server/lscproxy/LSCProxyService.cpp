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

#include "lscproxy/LSCProxyService.h"

LSCProxyService::LSCProxyService() :
    Service("lscProxy")
{
    this->Add("GetChannels", &LSCProxyService::GetChannels);
    this->Add("JoinChannels", &LSCProxyService::JoinChannels);
    this->Add("LeaveChannels", &LSCProxyService::LeaveChannels);
    this->Add("CreateChannel", &LSCProxyService::CreateChannel);
    this->Add("Configure", &LSCProxyService::Configure);
    this->Add("DestroyChannel", &LSCProxyService::DestroyChannel);
    this->Add("GetMembers", &LSCProxyService::GetMembers);
    this->Add("GetMember", &LSCProxyService::GetMember);
    this->Add("SendMessage", &LSCProxyService::SendMessage);
    this->Add("Invite", &LSCProxyService::Invite);
    this->Add("AccessControl", &LSCProxyService::AccessControl);
    this->Add("GetMyMessages", &LSCProxyService::GetMyMessages);
    this->Add("GetMessageDetails", &LSCProxyService::GetMessageDetails);
    this->Add("Page", &LSCProxyService::Page);
    this->Add("MarkMessagesRead", &LSCProxyService::MarkMessagesRead);
}

PyResult LSCProxyService::GetChannels(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "GetChannels called - stub");
    return new PyList();
}

PyResult LSCProxyService::JoinChannels(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "JoinChannels called - returning empty list");
    return new PyList();
}

PyResult LSCProxyService::LeaveChannels(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "LeaveChannels called - returning empty list");
    return new PyList();
}

PyResult LSCProxyService::CreateChannel(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "CreateChannel called - stub");
    return new PyInt(0);
}

PyResult LSCProxyService::Configure(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "Configure called - stub");
    return PyStatic.NewNone();
}

PyResult LSCProxyService::DestroyChannel(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "DestroyChannel called - stub");
    return PyStatic.NewNone();
}

PyResult LSCProxyService::GetMembers(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "GetMembers called - stub");
    return new PyList();
}

PyResult LSCProxyService::GetMember(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "GetMember called - stub");
    return PyStatic.NewNone();
}

PyResult LSCProxyService::SendMessage(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "SendMessage called - stub");
    return PyStatic.NewNone();
}

PyResult LSCProxyService::Invite(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "Invite called - stub");
    return PyStatic.NewNone();
}

PyResult LSCProxyService::AccessControl(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "AccessControl called - stub");
    return PyStatic.NewNone();
}

PyResult LSCProxyService::GetMyMessages(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "GetMyMessages called - stub");
    return new PyList();
}

PyResult LSCProxyService::GetMessageDetails(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "GetMessageDetails called - stub");
    return PyStatic.NewNone();
}

PyResult LSCProxyService::Page(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "Page called - stub");
    return PyStatic.NewNone();
}

PyResult LSCProxyService::MarkMessagesRead(PyCallArgs& call)
{
    sLog.Debug("LSCProxyService", "MarkMessagesRead called - stub");
    return PyStatic.NewNone();
}
