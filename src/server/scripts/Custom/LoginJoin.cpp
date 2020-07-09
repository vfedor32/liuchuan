/**
    ���˼���ʱ��ӭ������ʾ��
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"
#include "ChannelMgr.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Util.h"




class LoginJoin : public PlayerScript{
public:

    LoginJoin() : PlayerScript("LoginJoin") { }

    void OnLogin(Player* player) override {



        //������ʾ -- peipei
        Player* players = player->GetSession()->GetPlayer();
        

        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "RRRRRRRR1");


        //����ϵͳ������Ϣ
        SessionMap sessions = sWorld->GetAllSessions();
        for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr) {

            if (itr->second && itr->second->GetPlayer() && itr->second->GetPlayer()->IsInWorld())
            {
                if (Player* plr = itr->second->GetPlayer())
                {

                    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "sssssssss1 %s - %s");

                    sWorld->SendServerMessage(SERVER_MSG_STRING, "server 11111 to", players);
                    sWorld->SendServerMessage(SERVER_MSG_STRING, "server 2222222 to", plr);
                }

            }

        }



    }
};




void AddSC_JionChatScripts() {
    new LoginJoin();
}

