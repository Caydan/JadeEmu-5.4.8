 /*
* Copyright (C) 2008-YYYY TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2015-2016 Blazed WoW <http://www.blazedwow.com>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
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

/* ScriptData
SDName: Boss_Bloodmage_Thalnos
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptPCH.h"

enum eNums
{
    SAY_AGGRO               = 1,
    SAY_SPIRITGALE          = 2,
    SAY_EVICTSOUL           = 3,
    SAY_HEAL_PCT            = 4,
    SAY_KILL                = 5,
    
    SPELL_EVICTSOULS= 115297, // Evict Soul
    SPELL_CRUSADER= 115139,  // RISE CRUSADER
    SPELL_SPIRITS= 115147,  // Empowerign Spirits (Cadaveres de Rise Crusader)
    SPELL_SPIRITGALE= 115290, // En Rage Boss

};


class boss_bloodmage_thalnos : public CreatureScript
{
public:
    boss_bloodmage_thalnos() : CreatureScript("boss_bloodmage_thalnos") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_bloodmage_thalnosAI (creature);
    }
    
    
       struct boss_bloodmage_thalnosAI : public ScriptedAI
    {
        boss_bloodmage_thalnosAI(Creature* creature) : ScriptedAI(creature) {}
        
        
        bool HpYell;
        
        // Control de Tiempos !
        uint32 EVICTSOULS_Timer;
        uint32 CRUSADER_Timer;
        uint32 SPIRITS_Timer;
        uint32 SPIRITGALE_Timer;


        void reset()
       {
            HpYell = false;
            EVICTSOULS_Timer = 10000;
            CRUSADER_Timer = 50000;
            SPIRITS_Timer = 520000;
            SPIRITGALE_Timer = 10000;
       } 

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*Victim*/)
        {
            Talk(SAY_KILL);
        }

        void UpdateAI(const uint32 diff)
        {
            //If we are <50% hp
            if (!HpYell && !HealthAbovePct(50))
            {
                Talk(SAY_HEAL_PCT);
                HpYell = true;
            }
         
          // SPELL EVICTSOUL (Timer EVICTSOUL_Timer
            if (EVICTSOULS_Timer <= diff)
            {
                Talk(SAY_EVICTSOUL);              
                DoCastVictim(SPELL_EVICTSOULS);
                EVICTSOULS_Timer = urand(10000, 15000);
            }
            else EVICTSOULS_Timer -= diff;
         
         
         // SPELL_CRUSADER (Timer CRUSADER_Timer
         
         if (CRUSADER_Timer <= diff)
         {
               DoCast(SPELL_CRUSADER);
               CRUSADER_Timer = urand (50000, 52000);
         }
         
         else CRUSADER_Timer -= diff;
         
         // SPELL_SPIRITS (Timer SPIRITS_Timer)
         
         if (SPIRITS_Timer <= diff)
         {
               DoCast(SPELL_SPIRITS);
               SPIRITS_Timer = urand (52000, 54000);
         }
         
         else SPIRITS_Timer -= diff;
         
         // SPELL_SPIRITGALE (Timer SPIRITGALE_Timer)
         
         if (SPIRITGALE_Timer <= diff)
         {
              Talk(SAY_SPIRITGALE);        
              DoCastVictim(SPELL_SPIRITGALE);
              SPIRITGALE_Timer = urand (10000, 20000);
         }
         
         else SPIRITGALE_Timer -= diff;
         
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_bloodmage_thalnos()
{
    new boss_bloodmage_thalnos();
}
