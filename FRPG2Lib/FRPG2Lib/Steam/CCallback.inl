#pragma once

class CCallbackBase
{
    void** vtable;
    bool registered;
    int callbackID;
};

template<class T, class P, bool bGameserver = false>
class CCallback : public CCallbackBase
{
    T* m_pObj;
    void (T::* m_Func)(P*);
};