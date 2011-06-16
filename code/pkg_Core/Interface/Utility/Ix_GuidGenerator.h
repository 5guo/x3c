/*! \file Ix_GuidGenerator.h
 *  \brief ����GUID�������Ľӿ� Ix_GuidGenerator
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.22
 */
#ifndef X3_UTIL_IGUIDGENERATOR_H_
#define X3_UTIL_IGUIDGENERATOR_H_

#include <XComPtr.h>

X3CLSID_DEFINE(CLSID_GuidGenerator, "8c14f0c5-7795-4ec3-b13a-982f653a700a");

//! ȫ��Ψһ����������Ľӿ�
/*!
    \interface Ix_GuidGenerator
    \ingroup _GROUP_UTILITY_
    \see x3::CLSID_GuidGenerator
*/
class Ix_GuidGenerator
{
public:
    virtual ~Ix_GuidGenerator() {}

    //! �����µ�GUID��
    virtual std::wstring CreateGuid(bool withBrackets = false) = 0;

    //! �õ�û�����˴����ŵ�GUID��
    virtual std::wstring RemoveGuidBrackets(const std::wstring& uid) = 0;

    //! �õ���ǰ����ʱ����ַ�������ʽΪ��YYYY-MM-DD HH:MM:SS��
    virtual std::wstring GetCurrentTimeString(bool hasYear = true) = 0;

    //! ����ΨһID����ǰ��������ʱ��Ч
    virtual ULONG CreateID(long type = 0) = 0;
};

namespace x3 {

//! �����µ�GUID��
/*!
    \ingroup _GROUP_UTILITY_
    \see RemoveGuidBrackets, Ix_GuidGenerator
*/
inline std::wstring CreateGuid(bool withBrackets = false)
{
    Cx_Interface<Ix_GuidGenerator> pIFGenerator(x3::CLSID_GuidGenerator);
#ifdef ASSERT
    ASSERT(pIFGenerator.IsNotNull());
#endif
    return pIFGenerator->CreateGuid(withBrackets);
}

//! �õ�û�����˴����ŵ�GUID��
/*!
    \ingroup _GROUP_UTILITY_
    \see CreateGuid, Ix_GuidGenerator
*/
inline std::wstring RemoveGuidBrackets(const std::wstring& uid)
{
    Cx_Interface<Ix_GuidGenerator> pIFGenerator(x3::CLSID_GuidGenerator);
#ifdef ASSERT
    ASSERT(pIFGenerator.IsNotNull());
#endif
    return pIFGenerator->RemoveGuidBrackets(uid);
}

//! ����ΨһID����ǰ��������ʱ��Ч
/*!
    \ingroup _GROUP_UTILITY_
    \see Ix_GuidGenerator
*/
inline ULONG GuidCreateID(long type = 0)
{
    Cx_Interface<Ix_GuidGenerator> pIFGenerator(x3::CLSID_GuidGenerator);
#ifdef ASSERT
    ASSERT(pIFGenerator.IsNotNull());
#endif
    return pIFGenerator->CreateID(type);
}

//! �õ���ǰ����ʱ����ַ�������ʽΪ��YYYY-MM-DD HH:MM:SS��
/*!
    \ingroup _GROUP_UTILITY_
*/
inline std::wstring GetCurrentTimeString(bool hasYear = true)
{
    Cx_Interface<Ix_GuidGenerator> pIFGenerator(x3::CLSID_GuidGenerator);
#ifdef ASSERT
    ASSERT(pIFGenerator.IsNotNull());
#endif
    return pIFGenerator->GetCurrentTimeString(hasYear);
}

} // x3

#endif // X3_UTIL_IGUIDGENERATOR_H_
