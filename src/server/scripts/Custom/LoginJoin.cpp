/**
   玩家进入游戏提示信息
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




        //新人提示 -- peipei
        Player* players = player->GetSession()->GetPlayer();


        //随机欢迎语
        std::string _message;

        int rodomId = urand(0, 5);

        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "1111111 %s", rodomId);
        if(rodomId == 0)
            _message = UnicodeToUtf8(L"骑着心爱的小摩托快速冲进入");
        else if (rodomId == 1)
            _message = UnicodeToUtf8(L"唱着小曲来看大家了");
        else if (rodomId == 2)
            _message = UnicodeToUtf8(L"听说有人欺负我兄弟");
        else if (rodomId == 3)
            _message = UnicodeToUtf8(L"来看大家了,掌声欢迎");
        else if (rodomId == 4)
            _message = UnicodeToUtf8(L"直冲冲的冲进来,势不可挡...");
        else if (rodomId == 5)
            _message = UnicodeToUtf8(L"一脸怒气的冲进来,大家可别惹他");
        else
            _message = UnicodeToUtf8(L"一脸怒气的冲进来,大家可别惹他");





        if (players)
        {
            std::string team;
            std::string plrrace;
            std::string plrclass;


            if (players->GetTeamId() == TEAM_ALLIANCE)	
                team = UnicodeToUtf8(L"|cff3399FF联盟|r");
            else if(players->GetTeamId() == TEAM_HORDE)
                team = UnicodeToUtf8(L"|cffCC0000部落|r");
            else
                team = UnicodeToUtf8(L"|cffCC0000熊猫人中立|r");


            switch (players->getRace()) {
            case RACE_HUMAN:
                plrrace = UnicodeToUtf8(L"人类");
                break;
            case RACE_ORC:
                plrrace = UnicodeToUtf8(L"兽人");
                break;
            case RACE_DWARF:
                plrrace = UnicodeToUtf8(L"矮人");
                break;
            case RACE_NIGHTELF:
                plrrace = UnicodeToUtf8(L"暗夜精灵");
                break;
            case RACE_UNDEAD_PLAYER:
                plrrace = UnicodeToUtf8(L"亡灵");
                break;
            case RACE_TAUREN:
                plrrace = UnicodeToUtf8(L"牛头人");
                break;
            case RACE_GNOME:
                plrrace = UnicodeToUtf8(L"侏儒");
                break;
            case RACE_TROLL:
                plrrace = UnicodeToUtf8(L"巨魔");
                break;
            case RACE_BLOODELF:
                plrrace = UnicodeToUtf8(L"血精灵");
                break;
            case RACE_DRAENEI:
                plrrace = UnicodeToUtf8(L"德莱尼"); 
                break;
            case RACE_GOBLIN:
                plrrace = UnicodeToUtf8(L"熊猫人"); 
                    break;
            }
            switch (players->getClass()) {
            case CLASS_MAGE:
                plrclass = UnicodeToUtf8(L"|cff40C7EB法师|r");
                break;
            case CLASS_SHAMAN:
                plrclass = UnicodeToUtf8(L"|cff0070DE萨满祭祀|r");
                break;
            case CLASS_WARRIOR:
                plrclass = UnicodeToUtf8(L"|cffC79C6E战士|r");
                break;
            case CLASS_PALADIN:
                plrclass = UnicodeToUtf8(L"|cffF58CBA圣骑士|r");
                break;
            case CLASS_WARLOCK:
                plrclass = UnicodeToUtf8(L"|cff8787ED术士|r");
                break;
            case CLASS_HUNTER:
                plrclass = UnicodeToUtf8(L"|cffABD473猎人|r");
                break;
            case CLASS_ROGUE:
                plrclass = UnicodeToUtf8(L"|cffFFF569潜行者|r");
                break;
            case CLASS_DRUID:
                plrclass = UnicodeToUtf8(L"|cffFF7D0A德鲁伊|r");
                break;
            case CLASS_PRIEST:
                plrclass = UnicodeToUtf8(L"|cffFFFFFF牧师|r");
                break;
            case CLASS_DEATH_KNIGHT:
                plrclass = UnicodeToUtf8(L"|cffC41F3B死亡骑士|r");
                break;
            case CLASS_MONK:
                plrclass = UnicodeToUtf8(L"|cffABD473武僧|r");
                break;
            case CLASS_DEMON_HUNTER:
                plrclass = UnicodeToUtf8(L"|cffC41F3B恶魔猎人|r");
                break;
            }



            //发送系统公告信息
            SessionMap sessions = sWorld->GetAllSessions();
            for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr) {

                if (Player* plr = itr->second->GetPlayer()) {

                    std::string announce = "";
                    std::string name = players->GetName();

                    announce = UnicodeToUtf8(L"|cffffcc00[进入游戏]:|r【%s】|cffff0000【%s】|r|cffff0000【%s】|r|cffb2d235%s");
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

