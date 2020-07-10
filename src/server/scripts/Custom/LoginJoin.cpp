/**
   ��ҽ�����Ϸ��ʾ��Ϣ
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"
#include "ChannelMgr.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Util.h"






class LoginJoin : public PlayerScript {
public:

    LoginJoin() : PlayerScript("LoginJoin") { }

    void OnLogin(Player* player) override {




        //������ʾ -- peipei
        Player* players = player->GetSession()->GetPlayer();


        //�����ӭ��
        std::string _message;

        int rodomId = urand(0, 5);

        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "1111111 %s", rodomId);
        if(rodomId == 0)
            _message = UnicodeToUtf8(L"�����İ���СĦ�п��ٳ����");
        else if (rodomId == 1)
            _message = UnicodeToUtf8(L"����С�����������");
        else if (rodomId == 2)
            _message = UnicodeToUtf8(L"��˵�����۸����ֵ�");
        else if (rodomId == 3)
            _message = UnicodeToUtf8(L"���������,������ӭ");
        else if (rodomId == 4)
            _message = UnicodeToUtf8(L"ֱ���ĳ����,�Ʋ��ɵ�...");
        else if (rodomId == 5)
            _message = UnicodeToUtf8(L"һ��ŭ���ĳ����,��ҿɱ�����");
        else
            _message = UnicodeToUtf8(L"һ��ŭ���ĳ����,��ҿɱ�����");





        if (players)
        {
            std::string team;
            std::string plrrace;
            std::string plrclass;


            if (players->GetTeamId() == TEAM_ALLIANCE)	
                team = UnicodeToUtf8(L"|cff3399FF����|r");
            else if(players->GetTeamId() == TEAM_HORDE)
                team = UnicodeToUtf8(L"|cffCC0000����|r");
            else
                team = UnicodeToUtf8(L"|cffCC0000��è������|r");


            switch (players->getRace()) {
            case RACE_HUMAN:
                plrrace = UnicodeToUtf8(L"����");
                break;
            case RACE_ORC:
                plrrace = UnicodeToUtf8(L"����");
                break;
            case RACE_DWARF:
                plrrace = UnicodeToUtf8(L"����");
                break;
            case RACE_NIGHTELF:
                plrrace = UnicodeToUtf8(L"��ҹ����");
                break;
            case RACE_UNDEAD_PLAYER:
                plrrace = UnicodeToUtf8(L"����");
                break;
            case RACE_TAUREN:
                plrrace = UnicodeToUtf8(L"ţͷ��");
                break;
            case RACE_GNOME:
                plrrace = UnicodeToUtf8(L"٪��");
                break;
            case RACE_TROLL:
                plrrace = UnicodeToUtf8(L"��ħ");
                break;
            case RACE_BLOODELF:
                plrrace = UnicodeToUtf8(L"Ѫ����");
                break;
            case RACE_DRAENEI:
                plrrace = UnicodeToUtf8(L"������"); 
                break;
            case RACE_GOBLIN:
                plrrace = UnicodeToUtf8(L"��è��"); 
                    break;
            }
            switch (players->getClass()) {
            case CLASS_MAGE:
                plrclass = UnicodeToUtf8(L"|cff40C7EB��ʦ|r");
                break;
            case CLASS_SHAMAN:
                plrclass = UnicodeToUtf8(L"|cff0070DE��������|r");
                break;
            case CLASS_WARRIOR:
                plrclass = UnicodeToUtf8(L"|cffC79C6Eսʿ|r");
                break;
            case CLASS_PALADIN:
                plrclass = UnicodeToUtf8(L"|cffF58CBAʥ��ʿ|r");
                break;
            case CLASS_WARLOCK:
                plrclass = UnicodeToUtf8(L"|cff8787ED��ʿ|r");
                break;
            case CLASS_HUNTER:
                plrclass = UnicodeToUtf8(L"|cffABD473����|r");
                break;
            case CLASS_ROGUE:
                plrclass = UnicodeToUtf8(L"|cffFFF569Ǳ����|r");
                break;
            case CLASS_DRUID:
                plrclass = UnicodeToUtf8(L"|cffFF7D0A��³��|r");
                break;
            case CLASS_PRIEST:
                plrclass = UnicodeToUtf8(L"|cffFFFFFF��ʦ|r");
                break;
            case CLASS_DEATH_KNIGHT:
                plrclass = UnicodeToUtf8(L"|cffC41F3B������ʿ|r");
                break;
            case CLASS_MONK:
                plrclass = UnicodeToUtf8(L"|cffABD473��ɮ|r");
                break;
            case CLASS_DEMON_HUNTER:
                plrclass = UnicodeToUtf8(L"|cffC41F3B��ħ����|r");
                break;
            }



            //����ϵͳ������Ϣ
            SessionMap sessions = sWorld->GetAllSessions();
            for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr) {

                if (Player* plr = itr->second->GetPlayer()) {

                    std::string announce = "";
                    std::string name = players->GetName();

                    announce = UnicodeToUtf8(L"|cffffcc00[������Ϸ]:|r��%s��|cffff0000��%s��|r|cffff0000��%s��|r|cffb2d235%s");
                    char message[2048];
                    sprintf(message, announce.c_str(), team.c_str(), name.c_str(), plrclass.c_str(), _message.c_str());


                    sWorld->SendServerMessage(SERVER_MSG_STRING, message, plr);
                }
            }
        }





    }
};




void AddSC_JoinChatScripts() {
    new LoginJoin();

}

