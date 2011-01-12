//! \file SysErrStr.h
//! \brief ����õ�ϵͳ������������ݵĺ��� GetSystemErrorString

#ifndef UTILFUNC_SYSERRSTR_H_
#define UTILFUNC_SYSERRSTR_H_

//! �õ�ϵͳ�������������
/*!
    \ingroup _GROUP_UTILFUNC
    \param errorcode �����룬���� GetLastError() ����ֵ�� HRESULT ֵ
    \return ������Ϣ��������
*/
inline std::wstring GetSystemErrorString(unsigned long errorcode)
{
    std::wstring retstr;
    wchar_t buf[21] = { 0 };

    if (errorcode != 0)
    {
        wchar_t* p = NULL;

#ifdef FormatMessage
        ::FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL, errorcode, 
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (wchar_t*)&p, 0, NULL);

        if (p != NULL)
        {
            retstr = p;
            ::LocalFree((HLOCAL)p);
        }
#endif

#ifdef _stprintf_s
        swprintf_s(buf, _countof(buf), L"[0x%x]", errorcode);
#endif
        retstr = buf + retstr;
    }

    return retstr;
}

#endif // UTILFUNC_SYSERRSTR_H_
