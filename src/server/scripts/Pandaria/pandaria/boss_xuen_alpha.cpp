/*
* Copyright (C) 2015-2015 Proyecto Skyfire EMU - Blazed <http://www.blazedwow.com/>
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

/* ScriptData
SDName: Boss_xuen_alpha
SD%Complete: 15% (En fase preliminar)
SDCategory: Boss_Xuen_Alpha
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"



enum Texts
{
     
};


enum Spells
{
     
     
};


enum Events
{
     
};


class boss_xuen_alpha : public CreatureScript
{

    public:
        boss_ordos() : CreatureScript("boss_xuen_alpha") { }
        
        struct boss_xuen_alphaAI : public ScriptedAI
        {
        boss_ordosAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() OVERRIDE
            {
             /*   _events.ScheduleEvent(EVENT_MAGMA_CRUSH, urand(10000, 13000)); // 10-13 */
            }

            void KilledUnit(Unit* victim) OVERRIDE
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                Talk(SAY_DEATH);
            }
    
            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                /* _events.ScheduleEvent(EVENT_ETERNAL_AGONY, 300000); // ENRAGE SPELL AFTER 5 MINUTES */
                Talk(SAY_AGGRO);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                      /*  case EVENT_ETERNAL_AGONY:
                            Talk(SAY_ETERNAL_AGONY);
                            DoCastVictim(SPELL_ETERNAL_AGONY);
                            _events.ScheduleEvent(EVENT_ETERNAL_AGONY, urand(10000, 25000));
                            break; */
                  
                    }
                }
                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
        };
            
        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_xuen_alphaAI(creature);
        }
};

void AddSC_boss_ordos()
{
    new boss_xuen_alpha();
}
