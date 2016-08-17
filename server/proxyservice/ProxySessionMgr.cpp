#include "ProxySessionMgr.h"

int ProxySessionManager::add_session(ACE_HANDLE fd, ProxySession* pSession)
{
	_mutex_lock.acquire();
	_sessions[fd] = pSession;
	_mutex_lock.release();
	return 0;
}

int ProxySessionManager::activate_session(ProxySession* pSession, short uid)
{
	int ret = -1;
	ACE_HANDLE fd = find_fd(pSession);
    
	if (-1 != fd)
	{
		_sessions[fd]->id = uid;
		ret = 0;
	}
    
	return ret;
}

int ProxySessionManager::activate_session(ACE_HANDLE fd, short uid)
{
	int ret = -1;
    
	if (nullptr != find_session(fd))
	{
		_sessions[fd]->id = uid;
		ret = 0;
	}
    
	return ret;
}

ProxySession* ProxySessionManager::find_session(ACE_HANDLE fd)
{
	std::map<short, ProxySession*>::iterator it = _sessions.find(fd);
    
	if (it != _sessions.end())
	{
		return it->second;
	}
    
	return nullptr;
}

ACE_HANDLE ProxySessionManager::find_fd(ProxySession* pSession)
{
	std::map<short, ProxySession*>::iterator it = _sessions.begin();
    
	for (; it != _sessions.end(); ++ it)
	{
		if (it->second == pSession)
		{
			return it->first;
		}
	}
    
	return -1;
}

int ProxySessionManager::del_session(ACE_HANDLE fd)
{
	_mutex_lock.acquire();
    
	int ret = -1;
    
	if (nullptr != find_session(fd))
	{
	    delete _sessions[fd];
		_sessions.erase(fd);
		ret = 0;
	}
    
	_mutex_lock.release();
	return ret;
}

int ProxySessionManager::del_session(ProxySession* pSession)
{
	_mutex_lock.acquire();
    
	int ret = -1;
    
	ACE_HANDLE fd = find_fd(pSession);
	if (-1 != fd)
	{	
        delete _sessions[fd];
		_sessions.erase(fd);
		ret = 0;
	}
    
	_mutex_lock.release();
	return ret;
}
