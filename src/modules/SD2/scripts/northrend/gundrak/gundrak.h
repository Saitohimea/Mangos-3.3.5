/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_GUNDRAK_H
#define DEF_GUNDRAK_H
/* Encounters
 * Slad'ran          = 0
 * Moorabi           = 1
 * Drakkari Colossus = 2
 * Gal'darah         = 3
 * Eck the Ferocious = 4
*/
enum
{
    MAX_ENCOUNTER          = 5,

    TYPE_SLADRAN           = 0,
    TYPE_MOORABI           = 1,
    TYPE_COLOSSUS          = 2,
    TYPE_GALDARAH          = 3,
    TYPE_ECK               = 4,

    NPC_SLADRAN            = 29304,
    NPC_MOORABI            = 29305,
    NPC_COLOSSUS           = 29307,
    NPC_ELEMENTAL          = 29573,
    NPC_LIVING_MOJO        = 29830,
    NPC_GALDARAH           = 29306,
    NPC_ECK                = 29932,
    NPC_INVISIBLE_STALKER  = 30298,                         // Caster and Target for visual spells on altar use
    NPC_RUIN_DWELLER       = 29920,

    GO_ECK_DOOR            = 192632,
    GO_ECK_UNDERWATER_DOOR = 192569,
    GO_GALDARAH_DOOR       = 192568,
    GO_EXIT_DOOR_L         = 193208,
    GO_EXIT_DOOR_R         = 193209,

    GO_ALTAR_OF_SLADRAN    = 192518,
    GO_ALTAR_OF_MOORABI    = 192519,
    GO_ALTAR_OF_COLOSSUS   = 192520,

    GO_SNAKE_KEY           = 192564,
    GO_TROLL_KEY           = 192567,
    GO_MAMMOTH_KEY         = 192565,
    GO_RHINO_KEY           = 192566,

    GO_BRIDGE              = 193188,
    GO_COLLISION           = 192633,

    SPELL_BEAM_MAMMOTH     = 57068,
    SPELL_BEAM_SNAKE       = 57071,
    SPELL_BEAM_ELEMENTAL   = 57072,

    TIMER_VISUAL_ALTAR     = 3000,
    TIMER_VISUAL_BEAM      = 2500,
    TIMER_VISUAL_KEY       = 2000
};

typedef std::map<uint8, uint32> TypeTimerMap;
typedef std::pair<uint8, uint32> TypeTimerPair;

class MANGOS_DLL_DECL instance_gundrak : public ScriptedInstance
{
    public:
        instance_gundrak(Map* pMap);
        ~instance_gundrak() {}

        void Initialize();

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);
        void OnCreatureDeath(Creature* pCreature);
        void OnCreatureEnterCombat(Creature* pCreature);
        void OnPlayerEnter(Player* pPlayer);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);
        void Update(uint32 uiDiff);

        bool IsValidLivingMojo(ObjectGuid callerGuid);
    protected:
        void DoAltarVisualEffect(uint8 uiType);
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;


        TypeTimerMap m_mAltarInProgress;
        TypeTimerMap m_mBeamInProgress;
        TypeTimerMap m_mKeyInProgress;

        GUIDList m_luiStalkerGUIDs;
        GUIDVector m_vStalkerCasterGuids;
        GUIDVector m_vStalkerTargetGuids;
        GUIDList m_lEckDwellerGuids;
        GUIDList m_lLivingMojoGuids;
};

#endif
