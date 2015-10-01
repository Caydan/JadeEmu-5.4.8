/*
 * Copyright (C) 2011-2015 Blazed EMU 5.4.8 <http://www.blazedwow.com/>
 * Author : Ares <Responsable de desarrollo>
 * Colaboración : Relax y Hefesto
 * 
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"

class npc_promo : public CreatureScript 

{
public:
    npc_promo() : CreatureScript("npc_promo") { } 
 
    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE 
    {
        player->ADD_GOSSIP_ITEM(7, "Escoge tu promocion: ", GOSSIP_SENDER_MAIN, 99);
		switch (player->getClass())
		{
				case CLASS_MONK: player->ADD_GOSSIP_ITEM(10, "Promocion de Monje", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+29); player->ADD_GOSSIP_ITEM(10, "Promocion Monje DPS", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+42); break;
				case CLASS_DRUID: player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Equilibrio", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+30); player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Feral", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+44); player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Restauracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+45); break;
				case CLASS_SHAMAN: player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Elemental", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+31); player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Mejora", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+46); player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Restauracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+47); break;
				case CLASS_PALADIN: player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Represion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+32); player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Sagrado", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+40); player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Proteccion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+41); break;
				case CLASS_WARRIOR: player->ADD_GOSSIP_ITEM(10, "Promocion de Guerrero Furia", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+33); player->ADD_GOSSIP_ITEM(10, "Promocion de Guerrero Proteccion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+48); break;
				case CLASS_PRIEST: player->ADD_GOSSIP_ITEM(10, "Promocion de Sacerdote Sombras", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+34); player->ADD_GOSSIP_ITEM(10, "Promocion de Sacerdote Sagrado", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+42); break;
				case CLASS_DEATH_KNIGHT: player->ADD_GOSSIP_ITEM(10, "Promocion de DK DPS", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+35); player->ADD_GOSSIP_ITEM(10, "Promocion de DK Tank", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+43); break;
				case CLASS_ROGUE: player->ADD_GOSSIP_ITEM(10, "Promocion de Picaro", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+36); break;
				case CLASS_HUNTER: player->ADD_GOSSIP_ITEM(10, "Promocion de Cazador", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+37); break;
				case CLASS_MAGE: player->ADD_GOSSIP_ITEM(10, "Promocion de Mago", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+38); break;
				case CLASS_WARLOCK: player->ADD_GOSSIP_ITEM(10, "Promocion de Brujo", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+39); break;
		}
        player->SEND_GOSSIP_MENU(1, creature->GetGUID()); 
        return true;
    }
 
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 actions) OVERRIDE
    {
	    
		if (player->getLevel() == 90) 
		{
            player->GetSession()->SendAreaTriggerMessage("No puedes recibir la promocion mas de una vez.");
			player->CLOSE_GOSSIP_MENU();
			return true;
        }
		
        if (player->getLevel() == 1) 
        {
            uint32 accountID = player->GetSession()->GetAccountId();
            QueryResult result = CharacterDatabase.PQuery("SELECT COUNT(`guid`) FROM `characters` WHERE `account`=%u", accountID);
            Field *fields = result->Fetch();
            uint32 personajes = fields[0].GetUInt32();

            if (personajes == 1)		
                    {
					    if (actions == 99)
						{
						    player->CLOSE_GOSSIP_MENU();
						    return false;
						}
						player->GetSession()->SendAreaTriggerMessage("Has recibido tu promocion satisfactoriamente.");
                        player->GiveLevel(90);
						player->SetMoney(100000);
						switch(actions)
                              {
                                  case GOSSIP_ACTION_INFO_DEF+29: // Monje
								  player->AddItem(84544, 1);
								  player->AddItem(84545, 1);
								  player->AddItem(84543, 1);
								  player->AddItem(84546, 1);
								  player->AddItem(84547, 1);
								  player->AddItem(84458, 1);
								  player->AddItem(84457, 1);
								  player->AddItem(84460, 1);
								  player->AddItem(84349, 1);
								  player->AddItem(84344, 1);
								  player->AddItem(84351, 1);
								  player->AddItem(84352, 1);
								  player->AddItem(84347, 1);
								  player->AddItem(84346, 1);
								  player->Additem(80937, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
                                  
                                       								  
								  case GOSSIP_ACTION_INFO_DEF+30: // Druida Equilibrio
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+44: // Druida Feral
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+45: // Druida Restauracion
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+31: // Chaman Elemental
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+46: // Chaman Mejora
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+47: // Chaman Restauracion
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+32: // Paladin Represion
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+40: // Paladin Tank Sagrado
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+41: // Paladin Healer Proteccion
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+33: // Guerrero Furia
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+48: // Guerrero Proteccion
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+34: // Sacerdote Sombras
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+42: // Sacerdote Sagrado
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+35: // DK DPS
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
								  
								  case GOSSIP_ACTION_INFO_DEF+43: // DK Tank
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;								  

								  case GOSSIP_ACTION_INFO_DEF+36: // Picaro
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+37: // Cazador
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+38: // Mago
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;

								  case GOSSIP_ACTION_INFO_DEF+39: // Brujo
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->AddItem(200000, 1);
								  player->CLOSE_GOSSIP_MENU();
								  break;
	                          }
                    }			
			
			if (personajes > 1)
                    {
                        player->GetSession()->SendAreaTriggerMessage("Usted no puede recibir mas promociones, si no tiene un personaje 90 en esta IP/Cuenta mande un ticket.");
						player->CLOSE_GOSSIP_MENU();
						return true;
                    }
			
		    player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};
 
void AddSC_npc_promo() 
{
    new npc_promo(); 
}
