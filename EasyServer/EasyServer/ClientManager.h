#pragma once

#include <map>
#include <WinSock2.h>

class ClientSession ;
struct PacketHeader ;

class ClientManager
{
public:
	ClientManager() : mClientIndex(0), mLastGCTick(0)
	{}

	ClientSession* CreateClient(SOCKET sock) ;
	
	void BroadcastPacket(ClientSession* from, PacketHeader* pkt) ;

	void OnPeriodWork() ;

private:
	void CollectGarbageSessions() ;

private:
	typedef std::map<SOCKET, ClientSession*> ClientList ;
	ClientList	mClientList ;
	int			mClientIndex ;

	DWORD		mLastGCTick ;
} ;

extern ClientManager* GClientManager ;