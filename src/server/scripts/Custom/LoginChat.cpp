/**
    This plugin can be used for common player customizations
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"
#include "ChannelMgr.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Util.h"



bool LoginChat_enabled;
std::string LoginChat_name;
int LoginChat_id;


class LoginChat : public PlayerScript{
public:

    LoginChat() : PlayerScript("LoginChat") { }

    void OnLogin(Player* player) override {

	    //std::string channelName = sConfigMgr->GetStringDefault("LoginChat.name", "world");
     //       QueryResult result = CharacterDatabase.Query("SELECT channelId FROM channels WHERE name = '%s'", channelName.c_str());

     //       if (!result) return;

    	//    if (ChannelMgr* cMgr = ChannelMgr::forTeam(player->GetTeamId()))
    	//    {
     //   	    if (Channel* channel = cMgr->GetJoinChannel("world", 9))
     //       		    channel->JoinChannel(player, "");
    	//	    cMgr->LoadChannels();
	    //}



        //新人提示 -- peipei
        Player* players = player->GetSession()->GetPlayer();
        

        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "RRRRRRRR1 %s", players->GetTeamId());

        //发送系统公告信息
        SessionMap sessions = sWorld->GetAllSessions();
        for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr) {

            TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "aaaaaaaa1 %s", players->GetTeamId());

            //如果是相同阵营
            //if (Player* plr = itr->second->GetPlayer()) {

     
                    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "aaaaaa2 %s",player->GetTeam());

                    std::string announce;
                    std::string name = players->GetName();

                    announce = "player '";
                    announce += name.c_str();
                    announce += "'join server ";

                    char message[2048];
                    sprintf(message, player->GetSession()->GetTrinityString(LANG_SYSTEMMESSAGE), announce.c_str());

                    sWorld->SendServerMessage(SERVER_MSG_STRING, message, players);

            //}
        }

        
        if (players)
        {
            std::string team;
            std::string plrrace;
            std::string plrclass;
            //if (players->GetTeamId() == TEAM_ALLIANCE)	team = UnicodeToUtf8(L"联盟");
            //else									        team = UnicodeToUtf8(L"部落");
            //switch (players->getRace()) {
            //case RACE_HUMAN:
            //    plrrace = UnicodeToUtf8(L"人类");
            //    break;
            //case RACE_ORC:
            //    plrrace = UnicodeToUtf8(L"兽人");
            //    break;
            //case RACE_DWARF:
            //    plrrace = UnicodeToUtf8(L"矮人");
            //    break;
            //case RACE_NIGHTELF:
            //    plrrace = UnicodeToUtf8(L"暗夜精灵");
            //    break;
            //case RACE_UNDEAD_PLAYER:
            //    plrrace = UnicodeToUtf8(L"亡灵");
            //    break;
            //case RACE_TAUREN:
            //    plrrace = UnicodeToUtf8(L"牛头人");
            //    break;
            //case RACE_GNOME:
            //    plrrace = UnicodeToUtf8(L"侏儒");
            //    break;
            //case RACE_TROLL:
            //    plrrace = UnicodeToUtf8(L"巨魔");
            //    break;
            //case RACE_BLOODELF:
            //    plrrace = UnicodeToUtf8(L"血精灵");
            //    break;
            //case RACE_DRAENEI:
            //    plrrace = UnicodeToUtf8(L"德莱尼");
            //    break;
            //}
            //switch (players->getClass()) {
            //case CLASS_MAGE:
            //    plrclass = UnicodeToUtf8(L"法师");
            //    break;
            //case CLASS_SHAMAN:
            //    plrclass = UnicodeToUtf8(L"萨满祭祀");
            //    break;
            //case CLASS_WARRIOR:
            //    plrclass = UnicodeToUtf8(L"战士");
            //    break;
            //case CLASS_PALADIN:
            //    plrclass = UnicodeToUtf8(L"圣骑士");
            //    break;
            //case CLASS_WARLOCK:
            //    plrclass = UnicodeToUtf8(L"术士");
            //    break;
            //case CLASS_HUNTER:
            //    plrclass = UnicodeToUtf8(L"猎人");
            //    break;
            //case CLASS_ROGUE:
            //    plrclass = UnicodeToUtf8(L"潜行者");
            //    break;
            //case CLASS_DRUID:
            //    plrclass = UnicodeToUtf8(L"德鲁伊");
            //    break;
            //case CLASS_PRIEST:
            //    plrclass = UnicodeToUtf8(L"牧师");
            //    break;
            //case CLASS_DEATH_KNIGHT:
            //    plrclass = UnicodeToUtf8(L"死亡骑士");
            //    break;
            //}
            //char pAnnounce[512];
            //// std::string str = "|cffffcc00[新人提示]:|r欢迎|cffff0000【%s】|r|cffb2d235加入" + team + "成为" + plrrace + "一" + plrclass + "|r";
            //std::string str = UnicodeToUtf8(L"|cffffcc00[新人提示]:|r欢迎|cffff0000【%s】|r|cffb2d235加入%s成为%s一%s|r");
            //sprintf((char*)pAnnounce, str.c_str(), players->GetName().c_str(), team.c_str(), plrrace.c_str(), plrclass.c_str());

            //sWorld->SendGlobalText(pAnnounce, 0);
            //players->IsFirstJoin = false;
        }
        //////////////////////////////////////////////////////////////////////////









    }
};

class login_chat_conf : public WorldScript
{
public:
    login_chat_conf() : WorldScript("login_chat_conf") { }

    void OnConfigLoad(bool reload) override
    {
        if (!reload) {
            LoginChat_enabled = sConfigMgr->GetBoolDefault("LoginChat.enabled",true);
            LoginChat_name = sConfigMgr->GetStringDefault("LoginChat.name", "world");
            LoginChat_id = sConfigMgr->GetIntDefault("LoginChat.id", 9);

            TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "RRRRRRRR8 %s", LoginChat_name);
        }
    }
};


void AddSC_LoginChatScripts() {
    new LoginChat();
    new login_chat_conf();
}

