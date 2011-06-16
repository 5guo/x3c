/*! \file Ix_ConfigDBFactory.h
 *  \brief �����������ݵĴ����ӿ� Ix_ConfigDBFactory
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.22
 */
#ifndef X3_UTIL_ICONFIGDBFACTORY_H_
#define X3_UTIL_ICONFIGDBFACTORY_H_

#include <XComPtr.h>

const X3CLSID X3CLS_ConfigDBFactory("6f3ca83f-6193-48ce-a188-24b2afb45432");

//! ���ݿ����ݶ�д����Ĵ����ӿ�
/*! �����ݿ����ɾ�Ĳ������ݽڵ�(Ix_ConfigData, Cx_ConfigSection)�ļ򻯷�ʽ���в�����\n
    Ix_ConfigData�ӿڵĲ��ֺ������¶����ˣ��� Cx_CfgDatabase ��Ӧ������˵����\n
    �����Ӽ�¼ʱ����ʹ�� \@NEWID ���ĳ���ֶ�ȡֵΪ(���ID+1)��\n
    �����ӻ��޸ļ�¼ʱ����ʹ����@��ͷ�ĺ����������� CURDATE(), CURTIME(), NOW() ���ڲ����Զ���Ϊ��Ӧ�����ݿ⺯������
    \interface Ix_ConfigDBFactory
    \ingroup _GROUP_UTILITY_
    \see X3CLS_ConfigDBFactory, Cx_CfgDatabase
*/
interface Ix_ConfigDBFactory
{
    //! ��Access���ݿ��ļ�
    /*!
        \param filename ���ݿ��ļ�ȫ��(*.mdb, *.accdb)
        \param dbuser ���ݿ��û���
        \param password ���û���Ӧ������
        \return ���ݿ����ݷ��ʶ���(Ix_ConfigData)��Ϊ�ն���ʱ��ʾʧ��
        \see Ix_ConfigData, Ix_ConfigTransaction, Cx_CfgDatabase
    */
    virtual Cx_Ptr OpenAccessDB(
        const std::wstring& filename, 
        const std::wstring& dbuser = L"", 
        const std::wstring& password = L"") = 0;

    //! ��SQLServer���ݿ�
    /*!
        \param server ���ݿ��������
        \param database ���ݿ���
        \param dbuser ���ݿ��û���
        \param password ���û���Ӧ������
        \return ���ݿ����ݷ��ʶ���(Ix_ConfigData)��Ϊ�ն���ʱ��ʾʧ��
        \see Ix_ConfigData, Ix_ConfigTransaction, Cx_CfgDatabase
    */
    virtual Cx_Ptr OpenSQLServerDB(
        const std::wstring& server, 
        const std::wstring& database, 
        const std::wstring& dbuser = L"", 
        const std::wstring& password = L"") = 0;
};

#endif // X3_UTIL_ICONFIGDBFACTORY_H_
