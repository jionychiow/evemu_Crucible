/*
	------------------------------------------------------------------------------------
	LICENSE:
	------------------------------------------------------------------------------------
	This file is part of EVEmu: EVE Online Server Emulator
	Copyright 2006 - 2008 The EVEmu Team
	For the latest information visit http://evemu.mmoforge.org
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
	Author:		Zhur
*/

#ifndef __CHARACTERDB_H_INCL__
#define __CHARACTERDB_H_INCL__

#include "../ServiceDB.h"

class PyRepObject;
class PyRepString;
class CharacterAppearance;
class ItemFactory;
class InventoryItem;
class Client;

class CharacterDB : public ServiceDB {
public:
	CharacterDB(DBcore *db);
	virtual ~CharacterDB();

	PyRepObject *GetCharacterList(uint32 accountID);
	PyRepObject *GetCharSelectInfo(uint32 characterID);
	PyRepObject *GetCharPublicInfo(uint32 characterID);
	PyRepObject *GetCharPublicInfo3(uint32 characterID);
	//PyRepObject *GetAgentPublicInfo(uint32 agentID);
	PyRepObject *GetOwnerNoteLabels(uint32 charID);
	PyRepObject *GetOwnerNote(uint32 charID, uint32 noteID);

	bool ValidateCharName(const char *name);
	InventoryItem *CreateCharacter2(uint32 accountID, ItemFactory &fact, const CharacterData &data, const CharacterAppearance &app, const CorpMemberInfo &corpData);
	bool GetCharItems(uint32 characterID, std::vector<uint32> &into);
	bool DeleteCharacter(uint32 characterID);

	PyRepObject *GetCharacterAppearance(uint32 characterID);

	bool GetInfoByBloodline(CharacterData &cdata, uint32 &shipTypeID);
	bool GetLocationCorporationByCareer(CharacterData &cdata);

	bool GetAttributesFromBloodline(CharacterData & cdata);
	bool GetAttributesFromAncestry(CharacterData & cdata);

	bool GetSkillsByRace(uint32 raceID, std::map<uint32, uint32> &into);
	bool GetSkillsByCareer(uint32 careerID, std::map<uint32, uint32> &into);
	bool GetSkillsByCareerSpeciality(uint32 careerSpecialityID, std::map<uint32, uint32> &into);

	/**
	 * Retrieves the character note from the database as a PyRepString pointer.
	 *
	 * @author LSMoura
	 */
	PyRepString *GetNote(uint32 ownerID, uint32 itemID);

	/**
	 * Stores the character note on the database, given the ownerID and itemID and the string itself.
	 *
	 * If the String is null or size zero, the entry is removed from the database.
	 *
	 * @return boolean true if success.
	 *
	 * @author LSMoura
	 */
	bool SetNote(uint32 ownerID, uint32 itemID, const char *str);
	
	PyRepObject *GetCharDesc(uint32 characterID);
	bool SetCharDesc(uint32 characterID, const char *str);

	uint32 AddOwnerNote(uint32 charID, const std::string &label, const std::string &content);
	bool EditOwnerNote(uint32 charID, uint32 noteID, const std::string &label, const std::string &content);
};

#endif