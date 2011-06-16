/*! \file Ix_StringTable.h
 *  \brief ���屾�ػ��ַ�����Ľӿ� Ix_StringTable
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.28
 */
#ifndef X3_XML_ISTRINGTABLE_H_
#define X3_XML_ISTRINGTABLE_H_

#include "Ix_Object.h"

X3CLSID_DEFINE(CLSID_StringTable, "b8c36b29-59c3-4db2-be43-fd4982e6e71d");

//! ���ػ��ַ�����Ľӿ�
/*! ���ػ��ַ���XML�ļ������������Ŀ¼�� Translations/Strings Ŀ¼��
    \interface Ix_StringTable
    \ingroup _GROUP_PLUGIN_XML_
    \see x3::CLSID_StringTable
*/
class Ix_StringTable
{
public:
    virtual ~Ix_StringTable() {}

    //! �õ�һ��ģ���ָ��ID���ƶ�Ӧ���ַ���ֵ
    /*!
        \param[out] value ʵ���ַ���ֵ
        \param[in] name ����ģ������ID���Ƶı�ʶ������ʽΪ��@��ͷ���ϡ�Module:IDS_XXX��
        \param[out] module ���name�е�ģ����
        \param[out] id ���name�еĴ�ID����
        \return �Ƿ��ȡ���ǿ�ֵ
    */
    virtual bool GetValue(std::wstring& value, const std::wstring& name, 
        std::wstring& module, std::wstring& id) = 0;

    //! �õ�һ��ģ���ָ��ID���ƶ�Ӧ���ַ���ֵ
    /*!
        \param[out] value ʵ���ַ���ֵ
        \param[in] module ģ����
        \param[in] id ��ID����
        \return �Ƿ��ȡ���ǿ�ֵ
    */
    virtual bool GetValue(std::wstring& value, 
        const std::wstring& module, const std::wstring& id) = 0;

    //! ����ָ��Ŀ¼�µ��ַ���XML�ļ�
    /*!
        \param path �ַ���XML�ļ�����Ŀ¼�ľ���·��
        \return ���ص��ļ���
    */
    virtual long LoadFiles(const std::wstring& path) = 0;

    //! �õ�һ��ģ���ָ��ID���ƶ�Ӧ���ַ���ֵ
    /*!
        \param[in] module ģ����
        \param[in] id ��ID����
        \param[out] hasvalue ����Ƿ��ȡ���ǿ�ֵ��ΪNULL�����
        \return ʵ���ַ���ֵ
    */
    virtual std::wstring GetValue(const std::wstring& module, 
        const std::wstring& id, bool* hasvalue = NULL) = 0;
};

#ifdef X3_CORE_XCOMPTR_H_
namespace x3 {
//! �õ�һ��ģ���ָ��ID���ƶ�Ӧ���ַ���ֵ
/*!
    \param[in] module ģ����
    \param[in] id ��ID����
    \param[out] hasvalue ����Ƿ��ȡ���ǿ�ֵ��ΪNULL�����
    \return ʵ���ַ���ֵ���մ���ʾû��ֵ
*/
inline std::wstring GetStringValue(const std::wstring& module, 
    const std::wstring& id, bool* hasvalue = NULL)
{
    Cx_Interface<Ix_StringTable> pIFTable(x3::CLSID_StringTable);
    return pIFTable ? pIFTable->GetValue(module, id, hasvalue) : std::wstring();
}
} // x3
#endif

#endif // X3_XML_ISTRINGTABLE_H_
