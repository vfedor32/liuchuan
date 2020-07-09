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
#include "Log.h"


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

        

        //������ʾ -- peipei
        Player* players = player->GetSession()->GetPlayer();

        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "222RRRRRRRR %s", players->GetTeamId());


        if (players)
        {
            std::string team;
            std::string plrrace;
            std::string plrclass;
            //if (players->GetTeamId() == TEAM_ALLIANCE)	team = UnicodeToUtf8(L"����");
            //else									        team = UnicodeToUtf8(L"����");
            //switch (players->getRace()) {
            //case RACE_HUMAN:
            //    plrrace = UnicodeToUtf8(L"����");
            //    break;
            //case RACE_ORC:
            //    plrrace = UnicodeToUtf8(L"����");
            //    break;
            //case RACE_DWARF:
            //    plrrace = UnicodeToUtf8(L"����");
            //    break;
            //case RACE_NIGHTELF:
            //    plrrace = UnicodeToUtf8(L"��ҹ����");
            //    break;
            //case RACE_UNDEAD_PLAYER:
            //    plrrace = UnicodeToUtf8(L"����");
            //    break;
            //case RACE_TAUREN:
            //    plrrace = UnicodeToUtf8(L"ţͷ��");
            //    break;
            //case RACE_GNOME:
            //    plrrace = UnicodeToUtf8(L"٪��");
            //    break;
            //case RACE_TROLL:
            //    plrrace = UnicodeToUtf8(L"��ħ");
            //    break;
            //case RACE_BLOODELF:
            //    plrrace = UnicodeToUtf8(L"Ѫ����");
            //    break;
            //case RACE_DRAENEI:
            //    plrrace = UnicodeToUtf8(L"������");
            //    break;
            //}
            //switch (players->getClass()) {
            //case CLASS_MAGE:
            //    plrclass = UnicodeToUtf8(L"��ʦ");
            //    break;
            //case CLASS_SHAMAN:
            //    plrclass = UnicodeToUtf8(L"��������");
            //    break;
            //case CLASS_WARRIOR:
            //    plrclass = UnicodeToUtf8(L"սʿ");
            //    break;
            //case CLASS_PALADIN:
            //    plrclass = UnicodeToUtf8(L"ʥ��ʿ");
            //    break;
            //case CLASS_WARLOCK:
            //    plrclass = UnicodeToUtf8(L"��ʿ");
            //    break;
            //case CLASS_HUNTER:
            //    plrclass = UnicodeToUtf8(L"����");
            //    break;
            //case CLASS_ROGUE:
            //    plrclass = UnicodeToUtf8(L"Ǳ����");
            //    break;
            //case CLASS_DRUID:
            //    plrclass = UnicodeToUtf8(L"��³��");
            //    break;
            //case CLASS_PRIEST:
            //    plrclass = UnicodeToUtf8(L"��ʦ");
            //    break;
            //case CLASS_DEATH_KNIGHT:
            //    plrclass = UnicodeToUtf8(L"������ʿ");
            //    break;
            //}
            //char pAnnounce[512];
            //// std::string str = "|cffffcc00[������ʾ]:|r��ӭ|cffff0000��%s��|r|cffb2d235����" + team + "��Ϊ" + plrrace + "һ" + plrclass + "|r";
            //std::string str = UnicodeToUtf8(L"|cffffcc00[������ʾ]:|r��ӭ|cffff0000��%s��|r|cffb2d235����%s��Ϊ%sһ%s|r");
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
            sConfigMgr->GetBoolDefault("LoginChat.enabled",true);
            sConfigMgr->GetStringDefault("LoginChat.name", "world");
            sConfigMgr->GetIntDefault("LoginChat.id", 9);
        }
    }
};


void AddLoginChatScripts() {
    new LoginChat();
    new login_chat_conf();
}

